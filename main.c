/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:17:43 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/06 18:07:50 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philo.h"

#include <stdio.h>

int			main(void)
{
	t_thread	*th;
//	pthread_t	pth_time;
//	int			end;

//	end = -1;
	th = NULL;
	th = ft_create_list(th);

	while (th)
	{
		printf("th num = %d\n", th->num);
		th = th->prev;
	}

/* 	while (++end < 7) */
/* 		pthread_join(th[end].pth_philo, NULL); */
/* 	pthread_join(th.pth_time, NULL); */
	return (0);
}
