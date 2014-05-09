/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:16:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/09 12:59:41 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_LIFE 10
# define EAT_T 2
# define REST_T 3
# define THINK_T 3
# define TIMEOUT 10

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
void					ft_exit(char *error);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_print(int num, int opt);
void					ft_print_2(int num, int opt);
size_t					ft_strlen(const char *s);

#endif
