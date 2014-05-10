/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:17:43 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/10 18:35:39 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
#include "philo.h"

static int		ft_check_life(t_thread *th, t_print *print, int i)
{
	t_thread		*tmp;

	tmp = th;
	while (i > 0)
	{
		if (tmp->life == 0)
		{
			tputs(tgoto(tgetstr("cm", NULL), 0, 7), 1, ft_tputs_putchar);
			ft_putstr_fd("The Philosopher ", 1);
			ft_putnbr_fd(tmp->num, 1);
			ft_putendl_fd(" is dead, long live the Philosopher", 1);
			return (ft_exit(th, th, print, 0));
		}
		tmp = tmp->next;
		i--;
	}
	return (1);
}

static void		ft_launch(t_thread *th, t_thread *tmp, int i)
{
	while (++i < 7)
	{
		pthread_create(&tmp->pth, NULL, ft_distrib_status, tmp);
		tmp = tmp->next;
	}
	i = -1;
	tmp = th;
	while (++i < 7)
	{
		pthread_join(tmp->pth, NULL);
		tmp = tmp->next;
	}
}

int				main(void)
{
	t_thread		*th;
	t_thread		*tmp;
	t_print			*print;
	int				i;

	i = -1;
	th = NULL;
	print = NULL;
	th = ft_create_list(th);
	ft_init();
	tmp = th;
	if ((print = (t_print*)malloc(sizeof(t_print))) == NULL)
		ft_error(th, 3);
	print->th = th;
	pthread_create(&print->pth, NULL, ft_print, print);
	ft_launch(th, tmp, i);
	pthread_join(print->pth, NULL);
	if (ft_check_life(th, print, i) == 0)
		return (0);
	tputs(tgoto(tgetstr("cm", NULL), 0, 7), 1, ft_tputs_putchar);
	ft_putendl_fd("Now, it is time... To DAAAAAAAANCE ! ! !", 1);
	return (ft_exit(th, th, print, 0));
}
