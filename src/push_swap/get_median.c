/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:37:29 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 15:05:09 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	copy(t_number *stack, int size)
{
	int		i;
	int		j;
	int		tmp;
	int		ret[size];

	i = 0;
	while (i < size)
	{
		ret[i] = stack[i].num;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (++j < size)
			if (ret[i] > ret[j])
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
		i++;
	}
	return (ret[size / 2]);
}

int			get_median(t_stack stacks, char stack)
{
	int		mediana;
	int		i;

	if (stack == 'a')
		return (copy(stacks.a, stacks.size_a));
	else if (stack == 'b')
	{
		mediana = stacks.b[0].mediana;
		i = 0;
		while (i < stacks.size_b && stacks.b[i].mediana == mediana)
			i++;
		return (copy(stacks.b, i));
	}
	else if (stack == '2')
	{
		mediana = stacks.a[0].mediana;
		i = 0;
		while (i < stacks.size_a && stacks.a[i].mediana == mediana)
			i++;
		return (copy(stacks.a, i));
	}
	return (0);
}
