/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 20:40:31 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <term.h>
#include <curses.h>
#include "philo.h"

void			ft_resting(t_thread *th)
{
	int			i;

	i = -1;
	while (++i < REST_T && th->life > 0)
	{
		usleep(1000000);
		th->life--;
	}
	status_0(th, th->prev, th->next);
}

void			ft_thinking(t_thread *th)
{
	int			i;

	i = -1;
	while (++i < THINK_T && th->life > 0)
	{
		usleep(1000000);
		th->life--;
	}
	pthread_mutex_unlock(&th->mutex);
	status_1(th, th->prev);
}

void			ft_eating(t_thread *th, t_thread *prev)
{
	int			i;

	i = -1;
	while (++i < EAT_T && th->life > 0)
		usleep(1000000);
	if (th->life > 0)
		th->life = MAX_LIFE;
	pthread_mutex_unlock(&prev->mutex);
	th->status = 1;
}

static void		ft_check_status(t_thread *th, t_thread *prev)
{
	if (th->status == 0)
		ft_resting(th);
	else if (th->status == 1)
		ft_thinking(th);
	else if (th->status == 2)
		ft_eating(th, prev);
}

void			*ft_distrib_status(void *th_data)
{
	t_thread	*th;
	int			timeout;
	int			i;

	th = (t_thread*)th_data;
	timeout = (int)time(NULL) + TIMEOUT;
	while (timeout >= (int)time(NULL) && th->life > 0)
	{
		i = 0;
		while (i < 7)
		{
			if (th->life == 0)
				return (th_data);
			th = th->next;
			i++;
		}
		ft_check_status(th, th->prev);
	}
	return (th_data);
}
