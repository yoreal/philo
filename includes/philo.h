/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:16:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/09 21:42:10 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_LIFE 10
# define EAT_T 3
# define REST_T 1
# define THINK_T 2
# define TIMEOUT 1200

# include <pthread.h>
# include <string.h>

typedef struct			s_thread
{
	pthread_t			pth;
	int					num;
	int					life;
	int					status;
	pthread_mutex_t		mutex;
	struct s_thread		*next;
	struct s_thread		*prev;
}						t_thread;

t_thread				*ft_create_list(t_thread *th);
void					*ft_distrib_status(void *th);
void					ft_resting(t_thread *th);
void					ft_thinking(t_thread *th);
void					ft_eating(t_thread *th, t_thread *prev);
void					status_0(t_thread *th, t_thread *prev, t_thread *next);
void					status_1(t_thread *th, t_thread *prev);
void					ft_exit(char *error);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_print(int num, int opt);
void					ft_print_2(int num, int opt);
size_t					ft_strlen(const char *s);

#endif
