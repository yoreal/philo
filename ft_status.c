/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:58:15 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/09 22:12:47 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

#include <stdio.h>
/*
static void		ft_critical(t_thread *th, t_thread *prev)
{
	printf("\033[33;01mcritical %d\033[00m\n", th->num);
	pthread_mutex_lock(&th->mutex);
	pthread_mutex_lock(&prev->mutex);
	th->status = 2;
}
*/
void			status_0(t_thread *th, t_thread *prev, t_thread *next)
{
	if (th->next->life < th->life || prev->life < th->life)
		th->status = 0;
//	if (th->next->life > th->life && prev->life > th->life)
	//	ft_critical(th, prev);
	else if (next->status != 2 && prev->status != 2)
	{
		if (pthread_mutex_trylock(&th->mutex) != 0)
		{
			pthread_mutex_unlock(&th->mutex);
			printf("\033[33;01mUnlocked %d\033[00m\n", th->num);
			pthread_mutex_trylock(&th->mutex);
		}
		if (pthread_mutex_trylock(&prev->mutex) != 0)
		{
			pthread_mutex_unlock(&prev->mutex);
			printf("\033[33;01mUnlocked %d\033[00m\n", th->num);
			pthread_mutex_trylock(&prev->mutex);
			prev->status = 0;
		}
		th->status = 2;
	}
	else if (pthread_mutex_trylock(&th->mutex) == 0)
		th->status = 1;
	else
		th->status = 0;
}

void			status_1(t_thread *th, t_thread *prev)
{
	if (th->next->life < th->life || prev->life < th->life)
		th->status = 0;
//	if (th->next->life > th->life && prev->life > th->life)
	//	ft_critical(th, prev);
	else if (pthread_mutex_trylock(&th->mutex) == 0 &&
		pthread_mutex_trylock(&prev->mutex) == 0)
		th->status = 2;
	else
		th->status = 0;
}
