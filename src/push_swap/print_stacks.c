/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:15:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 13:53:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_stack stacks)
{
	int     i;

	ft_putstr("--------\nSTACK A\n");
	i = 0;
	while (i < stacks.size_a)
	{
		ft_putnbr(stacks.a[i].num);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("--------\nSTACK B\n");
	i = 0;
	while (i < stacks.size_b)
	{
		ft_putnbr(stacks.b[i].num);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("--------\n");
}
