/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:52:25 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 16:32:38 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_result(char *str, long int n, int i, long int j)
{
	if (n < 0)
	{
		str[i] = '-';
		n = n * -1;
		i++;
	}
	if (n == 0)
	{
		str[i] = 48;
		i++;
	}
	else
	{
		while ((n / j) != 0)
			j = j * 10;
		j = j / 10;
		while (j >= 1)
		{
			str[i] = 48 + ((n / j) % 10);
			j = j / 10;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char		*temp;
	int			i;
	long int	j;

	i = n;
	j = 0;
	while ((i / 10) != 0)
	{
		j++;
		i = i / 10;
	}
	temp = ft_strnew(j + 2);
	i = 0;
	j = 1;
	temp = ft_itoa_result(temp, (long int)n, i, j);
	return (temp);
}
