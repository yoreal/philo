/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/08 12:06:57 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include "philo.h"

#include <stdio.h>

static void		ft_resting(t_thread *th, t_thread *prev)
{
	int		i;

	i = -1;
	printf("le philo %d se repose\n", th->num);
//	ft_print(th->num, 0);
	th->status = 1;
	while (++i < REST_T)
	{
		th->life--;
		usleep(1000000);
	}
	if (prev)
		prev = th;
//	ft_print_2(th->num, 0);
}

static void		ft_thinking(t_thread *th, t_thread *prev)
{
	int		i;

	i = -1;
	printf("le philo %d reflechit\n", th->num);
//	ft_print(th->num, 1);
	th->status = 2;
	while (++i < THINK_T)
	{
		th->life--;
		usleep(1000000);
	}
	if (prev)
		prev = th;
//	ft_print_2(th->num, 1);
}

static void		ft_eating(t_thread *th, t_thread *prev)
{
	if (prev)
		prev = th;
	printf("le philo %d mange\n", th->num);
//	ft_print(th->num, 2);
	th->status = 0;
	th->life = MAX_LIFE;
	usleep(EAT_T * 1000000);
//	ft_print_2(th->num, 2);
}

void			*ft_distrib_status(void *th_data)
{
	t_thread	*th;
	t_thread	*prev;
	int			timeout;

	th = (t_thread*)th_data;
	prev = th->prev;
	timeout = (int)time(NULL) + TIMEOUT;
	while (timeout != (int)time(NULL))
	{
		if (th->status == 0)
			ft_resting(th, prev);
		else if (th->status == 1)
			ft_thinking(th, prev);
		else if (th->status == 2)
			ft_eating(th, prev);
	}
	return (th_data);
}
