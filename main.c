/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:17:43 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/07 13:58:35 by jgranet          ###   ########.fr       */
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
//	pthread_t	pth_time;
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
//		usleep(300000);
		pthread_create(&tmp->pth, NULL, ft_distrib_status, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < 7)
		pthread_join(th[i].pth, NULL);
//	pthread_join(th.pth_time, NULL);
	return (0);
}
