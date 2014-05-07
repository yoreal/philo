/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 17:09:25 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/07 17:24:19 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_print(int num, int opt)
{
	if (opt == 0)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" se repose.", 1);
	}
	if (opt == 1)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" reflechit.", 1);
	}
	if (opt == 2)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" mange.", 1);
	}
}

void		ft_print_2(int num, int opt)
{
	if (opt == 0)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" a fini de se reposer.", 1);
	}
	if (opt == 1)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" a fini de reflechir.", 1);
	}
	if (opt == 2)
	{
		ft_putstr_fd("Le philosophe ", 1);
		ft_putnbr_fd(num, 1);
		ft_putendl_fd(" a fini de manger.", 1);
	}
}
