/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:29:33 by jgranet           #+#    #+#             */
/*   Updated: 2013/12/22 18:34:51 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_var(int *i, int *len)
{
	*i = 0;
	*len = 0;
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	ft_init_var(&i, &len);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				len = ft_putnbr(va_arg(ap, int));
			else if (format[i + 1] == 's')
				len = ft_putstr(va_arg(ap, char*));
			else if (format[i + 1] == 'c')
				len = ft_putchar((char)va_arg(ap, int));
			else
				len = ft_putchar(format[i]);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len + 1);
}
