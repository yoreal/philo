/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 13:21:42 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include "philo.h"
#include "./ft_printf/includes/ft_printf.h"

#include <stdio.h>

static void		ft_resting(t_thread *th)//, t_thread *prev)
{
	int			i;

	i = -1;
	th->status = 0;
	printf("le philo %d se repose, life = %d\n", th->num, th->life);
//	ft_print(th->num, 0);
	while (++i < REST_T && th->life > 0)
	{
		th->life--;
		printf("life = %d\n", th->life);
		usleep(1000000);
	}
/* 	if (prev) */
/* 		prev = th->prev; */
//	ft_print_2(th->num, 0);
}

static void		ft_thinking(t_thread *th)//, t_thread *prev)
{
	int			i;

	i = -1;
	th->status = 1;
	printf("le philo %d reflechit, life = %d\n", th->num, th->life);
//	ft_print(th->num, 1);
	while (++i < THINK_T && th->life > 0)
	{
		th->life--;
		printf("life = %d\n", th->life);
		usleep(1000000);
	}
/* 	if (prev) */
/* 		prev = th->prev; */
//	pthread_mutex_unlock(th->mutex);
//	ft_print_2(th->num, 1);
}

static void		ft_eating(t_thread *th, t_thread *prev)
{
	int			i;

	i = -1;
	th->status = 2;
/* 	if (prev) */
/* 		prev = th->prev; */
	printf("le philo %d mange, life = %d\n", th->num, th->life);
//	ft_print(th->num, 2);
	while (++i < EAT_T && th->life > 0)
	{
		th->life--;
		printf("life = %d\n", th->life);
		usleep(1000000);
	}
	if (th->life > 0)
		th->life = MAX_LIFE;
	pthread_mutex_unlock(&th->mutex);
	pthread_mutex_unlock(&prev->mutex);
//	ft_print_2(th->num, 2);
}


static void		ft_check_chopstick(t_thread *th, t_thread *prev, t_thread *next)
{
	if (th->status == 0)
	{
		if (th->life <= REST_T)
		{
			if (next->status != 2 && prev->status != 2)
			{
				if (pthread_mutex_trylock(&th->mutex) != 0)
				{
					pthread_mutex_unlock(&th->mutex);
					pthread_mutex_trylock(&th->mutex);
				}
				if (pthread_mutex_trylock(&prev->mutex) != 0)
				{
					pthread_mutex_unlock(&prev->mutex);
					pthread_mutex_trylock(&prev->mutex);
				}
				ft_eating(th, prev);
			}
			else if (pthread_mutex_lock(&th->mutex) == 0)
				ft_thinking(th);
			else
				ft_resting(th);
		}
		else
		{
			if (pthread_mutex_trylock(&th->mutex) == 0 && 
				pthread_mutex_trylock(&prev->mutex) == 0)
				ft_eating(th, prev);
			else if (pthread_mutex_trylock(&th->mutex) == 0)
				ft_thinking(th);
			else
				ft_resting(th);
		}
	}
	if (th->status == 1)
	{

	}
	if (th->status == 2)
	{

	}
}


void			*ft_distrib_status(void *th_data)
{
	t_thread	*th;
	t_thread	*prev;
	t_thread	*next;
	int			timeout;

	th = (t_thread*)th_data;
	prev = th->prev;
	next = th->next;
	timeout = (int)time(NULL) + TIMEOUT;

	while (timeout != (int)time(NULL) && th->life > 0)
	{
		ft_check_chopstick(th, prev, next);
	}
	printf("philo %d life = %d\n", th->num, th->life);
	return (th_data);
}
