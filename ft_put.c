/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 21:54:34 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 16:00:35 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <curses.h>
#include "philo.h"

static void	ft_print_end(t_thread *th)
{
	if (th->status == 0)
		ft_putstr_fd("\033[34;01mzZzZ\033[00m", 1);
	else if (th->status == 1)
		ft_putstr_fd("\033[33;01m????\033[00m", 1);
	else if (th->status == 2)
		ft_putstr_fd("\033[32;01mmiam\033[00m", 1);
	ft_putstr_fd("  \033[31;01mPV: \033[00m", 1);
	ft_putnbr_fd(th->life, 1);
}

void		ft_put_2(t_thread *th)
{
	if (th->num == 1)
		tputs(tgoto(tgetstr("cm", NULL), 9, 0), 1, ft_tputs_putchar);
	else if (th->num == 2)
		tputs(tgoto(tgetstr("cm", NULL), 9, 1), 1, ft_tputs_putchar);
	else if (th->num == 3)
		tputs(tgoto(tgetstr("cm", NULL), 9, 2), 1, ft_tputs_putchar);
	else if (th->num == 4)
		tputs(tgoto(tgetstr("cm", NULL), 9, 3), 1, ft_tputs_putchar);
	else if (th->num == 5)
		tputs(tgoto(tgetstr("cm", NULL), 9, 4), 1, ft_tputs_putchar);
	else if (th->num == 6)
		tputs(tgoto(tgetstr("cm", NULL), 9, 5), 1, ft_tputs_putchar);
	else if (th->num == 7)
		tputs(tgoto(tgetstr("cm", NULL), 9, 6), 1, ft_tputs_putchar);
	tputs(tgetstr("ce", NULL), 1, ft_tputs_putchar);
	ft_print_end(th);
}

void		ft_put(void)
{
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 1 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 2 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 3 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 4 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 5 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 6 ", 1);
	tputs(tgetstr("do", NULL), 1, ft_tputs_putchar);
	ft_putstr_fd("Philo 7 ", 1);
}
