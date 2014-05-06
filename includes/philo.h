/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:16:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/06 18:08:42 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_LIFE 10
# define EAT_T 2
# define REST_T 2
# define THINK_T 2
# define TIMEOUT 10000

# include <pthread.h>

typedef struct			s_thread
{
	pthread_t			pth_philo;
	int					num;
	int					life;
	int					status;
	pthread_mutex_t		mutex;
	struct s_thread		*next;
	struct s_thread		*prev;
}						t_thread;

t_thread				*ft_create_list(t_thread *th);
void					ft_exit(char *error);

#endif
