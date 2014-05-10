/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:29:33 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 23:06:50 by jgranet          ###   ########.fr       */
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
			i++;
		}
		else
			str = ft_charjoin(str, format[i]);
		i++;
	}
	ft_putstr_fd(str, 1);
	va_end(ap);
}
