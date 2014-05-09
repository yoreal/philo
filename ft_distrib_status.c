/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distrib_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 10:34:19 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 19:11:16 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include "philo.h"
#include "./ft_printf/includes/ft_printf.h"

#include <stdio.h>

void			ft_resting(t_thread *th)
{
	int			i;

	i = -1;
	th->status = 0;
	printf("le philo %d se \033[37;01mrepose\033[00m, life = %d\n", th->num, th->life);
	while (++i < REST_T && th->life > 0)
	{
		th->life--;
		usleep(1000000);
	}
	printf("le philo %d a fini de se \033[37;01mreposer\033[00m, life = %d\n", th->num, th->life);
}

void			ft_thinking(t_thread *th)
{
	int			i;

	i = -1;
	th->status = 1;
	printf("le philo %d \033[36;01mreflechit\033[00m, life = %d\n", th->num, th->life);
	while (++i < THINK_T && th->life > 0)
	{
		th->life--;
		usleep(1000000);
	}
	printf("le philo %d a fini de \033[36;01mreflechir\033[00m, life = %d\n", th->num, th->life);
	pthread_mutex_unlock(&th->mutex);
}

void			ft_eating(t_thread *th, t_thread *prev)
{
	int			i;

	i = -1;
	th->status = 2;
	printf("le philo %d \033[35;01mmange\033[00m, life = %d\n", th->num, th->life);
	while (++i < EAT_T && th->life > 0)
	{
		th->life--;
		usleep(1000000);
	}
	if (th->life > 0)
		th->life = MAX_LIFE;
	pthread_mutex_unlock(&th->mutex);
	pthread_mutex_unlock(&prev->mutex);
	printf("le philo %d a fini de \033[35;01mmanger\033[00m, life = %d\n", th->num, th->life);
}


static void		ft_check_status(t_thread *th, t_thread *prev, t_thread *next)
{
		if (th->status == 0)
			status_0(th, prev, next);
		else if (th->status == 1)
			status_1(th, prev);
		else if (th->status == 2)
			ft_thinking(th);
}

void			*ft_distrib_status(void *th_data)
{
	t_thread	*th;
	int			timeout;
	int			i;

	th = (t_thread*)th_data;
	timeout = (int)time(NULL) + TIMEOUT;
	i = 0;
	while (timeout >= (int)time(NULL) && th->life > 0)
	{
		ft_check_status(th, th->prev, th->next);
	}
	if (th->life == 0)
	{
		printf("\033[33;01mphilo %d life = %d\033[00m est mort\n", th->num, th->life);
		while (i < 7)
		{
			pthread_detach(th->pth);
			th = th->next;
			i++;
		}
	}
	printf("\033[34;01mphilo %d life = %d\033[00m\n", th->num, th->life);
	return (th_data);
}
