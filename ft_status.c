/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:58:15 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/09 19:58:58 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void		status_0(t_thread *th, t_thread *prev, t_thread *next)
{
	if (th->next->life < th->life || prev->life < th->life)
		ft_resting(th);
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
				prev->status = 0;
			}
			ft_eating(th, prev);
	}
	else if (pthread_mutex_trylock(&th->mutex) == 0)
		ft_thinking(th);
	else
		ft_resting(th);
}

void		status_1(t_thread *th, t_thread *prev)
{
	if (th->next->life < th->life || prev->life < th->life)
		ft_resting(th);
	if (pthread_mutex_trylock(&th->mutex) == 0 &&
		pthread_mutex_trylock(&prev->mutex) == 0)
		ft_eating(th, prev);
	else
		ft_resting(th);
}
