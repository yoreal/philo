/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:33:11 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 16:40:01 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

static t_thread		*ft_new(t_thread *tmp, t_thread *tmp2, int i)
{
	t_thread		*new;

	if ((new = (t_thread*)malloc(sizeof(t_thread))) == NULL)
		ft_error(tmp, 2);
	new->num = i;
	new->life = MAX_LIFE;
	pthread_mutex_init(&new->mutex, NULL);
	if (i != 1 && i % 2 == 0)
	{
		pthread_mutex_lock(&new->mutex);
		pthread_mutex_lock(&tmp2->mutex);
		new->status = 2;
	}
	else
		new->status = 0;
	if (i != 7)
		new->next = NULL;
	else
		new->next = tmp;
	if (i == 1)
		new->prev = NULL;
	else
		new->prev = tmp2;
	return (new);
}

t_thread			*ft_create_list(t_thread *th)
{
	int				i;
	t_thread		*tmp;
	t_thread		*tmp2;

	i = 2;
	if ((th = (t_thread*)malloc(sizeof(t_thread))) == NULL)
		ft_error(th, 1);
	th = ft_new(NULL, NULL, 1);
	tmp = th;
	tmp2 = th;
	while (i < 8)
	{
		th->next = ft_new(tmp, tmp2, i);
		i++;
		if (i != 8)
			th = th->next;
		tmp2 = th;
	}
	tmp->prev = th->next;
	return (tmp);
}
