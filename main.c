/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:17:43 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/09 18:24:04 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "philo.h"

#include <stdio.h>

static int		ft_check_life(t_thread *th, int i)
{
 	while (i > 0)
 	{
		if (th->life == 0)
		{
			ft_putendl_fd("un philosophe est mort, vive le philosophe !", 1);
			return (0);
		}
 		th = th->prev; 
		i--;
 	}
	return (1);
}

int				main(void)
{
	t_thread	*th;
	t_thread	*tmp;
	int			i;

	i = -1;
	th = NULL;
	th = ft_create_list(th);
	tmp = th;
	while (++i < 7)
	{
		pthread_create(&tmp->pth, NULL, ft_distrib_status, tmp);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < 7)
	{
		pthread_join(th->pth, NULL);
		th = th->next;
	}
	if (ft_check_life(th, i) == 0)
		return (0);
	ft_putendl_fd("Now, it is time... To DAAAAAAAANCE ! ! !", 1);
 	return (0);
}
