/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:58:15 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/10 20:41:39 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

static void		ft_check_chopstick(t_thread *th, t_thread *prev, int i)
{
	if (pthread_mutex_trylock(&th->mutex) != 0)
	{
		pthread_mutex_unlock(&th->mutex);
		pthread_mutex_trylock(&th->mutex);
		i++;
	}
	if (i == 1 && pthread_mutex_trylock(&prev->mutex) != 0)
	{
		pthread_mutex_unlock(&prev->mutex);
		pthread_mutex_trylock(&prev->mutex);
		prev->status = 0;
		i++;
	}
	if (i == 2)
		th->status = 2;
	else if (i == 1)
		th->status = 1;
	else
		th->status = 0;
}

void			status_0(t_thread *th, t_thread *prev, t_thread *next)
{
	int			i;

	i = 0;
	i++;
	if (pthread_mutex_trylock(&th->mutex) == 0 &&
		pthread_mutex_trylock(&prev->mutex) == 0)
		th->status = 2;
	else if (next->status != 2 && prev->status != 2)
		ft_check_chopstick(th, prev, i);
	else if (next->status != 2 && pthread_mutex_trylock(&th->mutex) == 0)
		th->status = 1;
	else
		th->status = 0;
}

void			status_1(t_thread *th, t_thread *prev)
{
	if (pthread_mutex_trylock(&th->mutex) == 0 &&
		pthread_mutex_trylock(&prev->mutex) == 0)
		th->status = 2;
	else
		th->status = 0;
}
