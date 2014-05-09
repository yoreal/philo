/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:27:50 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 18:20:37 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>

char		*ft_itoa(int n);
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_charjoin(char const *s, char const c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		ft_printf(const char *form, ...);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *str, int fd);

#endif
