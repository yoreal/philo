/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:38:01 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 18:12:11 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "philo.h"

void			ft_error(t_thread *th, int opt)
{
	t_thread	*tmp;

	if (opt == 2 || opt == 3)
	{
		while (th->next)
		{
			tmp = th;
			th = th->next;
			pthread_mutex_destroy(&tmp->mutex);
			free(tmp);
		}
		pthread_mutex_destroy(&th->mutex);
		free(th);
	}
	ft_putendl_fd("Malloc error.", 2);
	default_terminal_mode();
	exit(-1);
}

int				ft_exit(t_thread *th, t_thread *tmp, t_print *p, int i)
{
	static char	buffer[7] = {0};

	while (read(0, buffer, 7) > 0)
	{
		if (buffer[0] == 10)
		{
			pthread_detach(p->pth);
			free(p);
			while (++i < 7)
			{
				tmp = th;
				th = th->next;
				pthread_detach(tmp->pth);
				pthread_mutex_destroy(&tmp->mutex);
				free(tmp);
			}
			pthread_detach(th->pth);
			pthread_mutex_destroy(&th->mutex);
			free(th);
			break ;
		}
	}
	default_terminal_mode();
	exit(0);
	return (0);
}
