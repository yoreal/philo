/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 12:16:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/05/10 19:00:22 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_LIFE 10
# define EAT_T 3
# define REST_T 1
# define THINK_T 2
# define TIMEOUT 10

# include <pthread.h>
# include <string.h>
# include <termios.h>

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

typedef struct			s_print
{
	t_thread			*th;
	pthread_t			pth;
}						t_print;

void					default_terminal_mode(void);
int						ft_init(void);
int						ft_tputs_putchar(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_exit(t_thread *th, t_thread *tmp, t_print *p, int i);
t_thread				*ft_create_list(t_thread *th);
void					ft_error(t_thread *th, int opt);
void					ft_put(void);
void					ft_put_2(t_thread *th);
void					*ft_distrib_status(void *th);
void					ft_resting(t_thread *th);
void					ft_thinking(t_thread *th);
void					ft_eating(t_thread *th, t_thread *prev);
void					status_0(t_thread *th, t_thread *prev, t_thread *next);
void					status_1(t_thread *th, t_thread *prev);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_print(void *print);
size_t					ft_strlen(const char *s);

#endif
