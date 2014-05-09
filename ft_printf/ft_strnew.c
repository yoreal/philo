/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 09:34:58 by jgranet           #+#    #+#             */
/*   Updated: 2014/03/16 17:20:46 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
