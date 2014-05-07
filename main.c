/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:17:43 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/07 17:39:41 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "philo.h"

#include <stdio.h>

int			main(void)
{
	t_thread	*th;
	t_thread	*tmp;
	int			i;

	i = -1;
	th = NULL;
	th = ft_create_list(th);
	tmp = th;

/* 	afficher liste */
/* 	while (th) */
/* 	{ */
/* 		printf("th num = %d\n", th->num); */
/* 		th = th->prev; */
/* 	} */

	while (++i < 7)
	{
		pthread_create(&tmp->pth, NULL, ft_distrib_status, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < 7)
		pthread_join(th[i].pth, NULL);
	return (0);
}
