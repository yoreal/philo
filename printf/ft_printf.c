/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:29:33 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 09:48:44 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (format[i + 1] == 's')
				ft_putstr_fd(va_arg(ap, char*), 1);
			else if (format[i + 1] == 'c')
				ft_putchar_fd((char)va_arg(ap, int), 1);
			else
				ft_putchar_fd(format[i], 1);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
}
