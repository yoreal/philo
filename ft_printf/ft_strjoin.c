/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:17:50 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/09 18:17:57 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_charjoin(char const *s1, char const c)
{
	char	*str;

	if ((s1 == NULL) && c)
	{
		str = ft_strnew(2);
		str[0] = c;
		return (str);
	}
	if (!c && s1)
		return (ft_strdup(s1));
	if ((str = ft_strnew(ft_strlen(s1) + 2)) == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	str[ft_strlen(s1)] = c;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((s1 == NULL) && s2)
		return (ft_strdup(s2));
	if ((s2 == NULL) && s1)
		return (ft_strdup(s1));
	str = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
