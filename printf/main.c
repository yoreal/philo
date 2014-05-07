/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:44:12 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/07 17:34:20 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "./printf/includes/ft_printf.h"

int		main(int ac, char **av)
{
	int	i;
	i = -18;
//	while (i != 19)
//	{
//		ft_printf("ft[%d]printf\n", 18);
		printf("bite %d\n", 18);
//		ft_printf("ft[%d]printf\n", -18);
		printf("pr[%+d]intf\n", -18);
//		printf("\n");
//		i++;
//	}
	return (0);
}
