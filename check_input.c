/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:27:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/21 14:04:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_input(int ac, char **av, int begin)
{
	int		i;
	int		sign;

	sign = 0;
	while (av[begin])
	{
		i = 0;
		while (av[begin][i])
		{
			if (sign == 0 && (av[begin][i] == '-' || av[begin][i] == '+'))
			{
				sign = 1;
				i++;
			}
			if (av[begin][i] && !ft_isdigit(av[begin][i]))
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			i++;
		}
		begin++;
	}
}
