/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:27:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 16:17:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_input(int ac, char **av, int begin, t_flag flags)
{
	int		i;
	int		sign;

	sign = 0;
	while (av[begin])
	{
		i = 0;
		while (av[begin][i])
		{
			if (i == 0 && sign == 0 && av[begin][1] && (av[begin][i] == '-' ||
						av[begin][i] == '+'))
			{
				sign = 1;
				i++;
			}
			if (av[begin][i] && !ft_isdigit(av[begin][i]))
			{
				print_error(2, flags);
				exit(0);
			}
			i++;
		}
		begin++;
	}
}
