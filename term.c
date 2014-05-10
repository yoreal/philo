/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 20:45:23 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 12:46:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <curses.h>
#include "philo.h"

static char			*ft_getenv(char *tofind)
{
	size_t		i;
	size_t		len;
	extern char	**environ;

	len = ft_strlen(tofind);
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], tofind, len) && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}

int					ft_init(void)
{
	struct termios	term;

	if (tgetent(NULL, ft_getenv("TERM")) != 1)
	{
		ft_putendl_fd("Error: can't find TERM", 2);
		return (-1);
	}
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	tputs(tgetstr("vi", NULL), 1, ft_tputs_putchar);
	tputs(tgetstr("ti", NULL), 1, ft_tputs_putchar);
	return (0);
}

void				default_terminal_mode(void)
{
	struct termios	term;

	tputs(tgetstr("te", NULL), 1, ft_tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, ft_tputs_putchar);
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
}
