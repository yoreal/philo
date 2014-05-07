/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/07 17:46:59 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include "philo.h"

#include <stdio.h>

static void		ft_resting(t_thread *th, t_thread *prev)
{
	printf("le philo %d se repose\n", th->num);
//	ft_print(th->num, 0);
	th->status = 1;
	th->life -= REST_T;
	if (prev)
		prev = prev;
	usleep(REST_T * 1000000);
//	ft_print_2(th->num, 0);
}

static void		ft_thinking(t_thread *th, t_thread *prev)
{
	printf("le philo %d reflechit\n", th->num);
//	ft_print(th->num, 1);
	th->status = 2;
	th->life -= THINK_T;
	if (prev)
		prev = prev;
	usleep(THINK_T * 1000000);
//	ft_print_2(th->num, 1);
}

static void		ft_eating(t_thread *th, t_thread *prev)
{
	if (prev)
		prev = prev;
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
	int			time_spent;

	th = (t_thread*)th_data;
	prev = th->prev;
	timeout = (int)time(NULL) + TIMEOUT;
	time_spent = (int)time(NULL);
	while (timeout != (int)time(NULL))
	{
		if (th->status == 0)
			ft_resting(th, prev);
		else if (th->status == 1)
			ft_thinking(th, prev);
		else if (th->status == 2)
			ft_eating(th, prev);
		if (time_spent != (int)time(NULL))
		{
			if (th->status != 2)
				th->life--;
			time_spent = (int)time(NULL);
		}
	}
	return (th_data);
}
