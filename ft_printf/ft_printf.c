/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:29:33 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 17:19:18 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void		ft_create_str(char **str, const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		*str = ft_strjoin(*str, ft_itoa(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		*str = ft_strjoin(*str, va_arg(ap, char*));
	else if (format[i + 1] == 'c')
		*str = ft_charjoin(*str, (char)va_arg(ap, int));
	else
		*str = ft_charjoin(*str, format[i]);
}

void			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char		*str;

	i = 0;
	str = NULL;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_create_str(&str, format, i, ap);
/* 			if (format[i + 1] == 'd' || format[i + 1] == 'i') */
/* 				ft_putnbr_fd(va_arg(ap, int), 1); */
/* 			else if (format[i + 1] == 's') */
/* 				ft_putstr_fd(va_arg(ap, char*), 1); */
/* 			else if (format[i + 1] == 'c') */
/* 				ft_putchar_fd((char)va_arg(ap, int), 1); */
/* 			else */
/* 				ft_putchar_fd(format[i], 1); */
			i++;
		}
		else
			str = ft_charjoin(str, format[i]);
//			ft_putchar_fd(format[i], 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	va_end(ap);
}
