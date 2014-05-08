/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:33:11 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/08 12:03:14 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

static t_thread		*ft_new(t_thread *tmp, t_thread *tmp2, int i)
{
	t_thread		*new;

	if ((new = (t_thread*)malloc(sizeof(t_thread))) != NULL)
	{
		new->num = i;
		new->life = MAX_LIFE;
		new->status = 0;
		new->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
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
	return (NULL);
}

t_thread			*ft_create_list(t_thread *th)
{
	int				i;
	t_thread		*tmp;
	t_thread		*tmp2;
	
	i = 2;
	if ((th = (t_thread*)malloc(sizeof(t_thread))) == NULL)
		ft_exit("malloc error");
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
