/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:58:15 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/10 18:51:26 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void			status_0(t_thread *th, t_thread *prev, t_thread *next)
{
	if (th->next->life < th->life || prev->life < th->life)
		th->status = 0;
	else if (next->status != 2 && prev->status != 2)
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
			prev->status = 0;
		}
		th->status = 2;
	}
	else if (next->status != 2 && pthread_mutex_trylock(&th->mutex) == 0)
		th->status = 1;
	else
		th->status = 0;
}

void			status_1(t_thread *th, t_thread *prev)
{
	if (th->next->life < th->life || prev->life < th->life)
		th->status = 0;
	else if (pthread_mutex_trylock(&th->mutex) == 0 &&
		pthread_mutex_trylock(&prev->mutex) == 0)
		th->status = 2;
	else
		th->status = 0;
}
