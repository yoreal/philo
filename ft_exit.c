/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 16:38:01 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/06 16:59:30 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

#include <stdio.h>

void		ft_exit(char *error)
{
//	ft_putendl_fd(error, 2);
	printf("%s\n", error);
	exit(-1);
}
