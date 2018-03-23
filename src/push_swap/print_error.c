/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:13:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 15:45:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_error(int error_code, t_flag flags)
{
	if (flags.e == 1)
	{
		ft_putstr("\033[0;31m");
		ft_putstr_fd("Error\n", 2);
		if (error_code == 1)
			ft_putstr_fd("Some arguments are duplicates\n", 2);
		else if (error_code == 2)
			ft_putstr_fd("Some arguments are not integers\n", 2);
		else if (error_code == 3)
			ft_putstr_fd("Some arguments are bigger than an integer\n", 2);
		ft_putstr("\033[0m");
	}
	else
		ft_putstr_fd("Error\n", 2);
}
