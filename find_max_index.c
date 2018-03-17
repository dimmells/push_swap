/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:37:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 15:44:30 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_max_index(t_number *stack, int size)
{
	int		i;
	int		max;
	int		index;

	max = stack[0].num;
	index = 0;
	i = 1;
	while (i < size)
	{
		if (max < stack[i].num)
		{
			max = stack[i].num;
			index = i;
		}
		i++;
	}
	return (index);
}
