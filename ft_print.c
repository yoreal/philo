/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 17:09:25 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/10 18:16:33 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "philo.h"

void		*ft_print(void *print_data)
{
	t_print		*print;
	int			timeout;
	int			i;

	i = -1;
	print = (t_print*)print_data;
	timeout = (int)time(NULL) + TIMEOUT;
	ft_put();
	while (timeout >= (int)time(NULL) && print->th->life > 0)
	{
		ft_put_2(print->th);
		print->th = print->th->next;
	}
	while (++i < 7)
	{
		ft_put_2(print->th);
		print->th = print->th->next;
	}
	return (print_data);
}
