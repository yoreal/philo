/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/07 16:56:21 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include "philo.h"

#include <stdio.h>

static void		ft_resting(t_thread *th, t_thread *prev)
{
	printf("philo %d se repose, prev = %d\n", th->num, prev->num);
	th->status = 1;
	th->life--;
/* 	if (th->time == 0) */
/* 	{ */
/* 		th->time = REST_T; */
		usleep(REST_T * 1000000);
/* 	} */
/* 	else */
/* 		th->time--; */
}

static void		ft_thinking(t_thread *th, t_thread *prev)
{
	printf("philo %d reflechit, prev = %d\n", th->num, prev->num);
	th->status = 2;
	th->life--;
/* 	if (th->time == 0) */
/* 	{ */
/* 		th->time = THINK_T; */
		usleep(THINK_T * 1000000);
/* 	} */
/* 	else */
/* 		th->time--; */
}

static void		ft_eating(t_thread *th, t_thread *prev)
{
	printf("philo %d mange, prev = %d\n", th->num, prev->num);
	th->status = 0;
	th->life = MAX_LIFE;
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
		printf("time = %d\n", (int)time(NULL));
		if (th->status == 0)
			ft_resting(th, prev);
		else if (th->status == 1)
			ft_thinking(th, prev);
		else if (th->status == 2)
			ft_eating(th, prev);
	}
	return (th_data);
}
