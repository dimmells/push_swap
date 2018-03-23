/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:54:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 14:18:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sort(t_number *stack, int size)
{
	int		i;
	int		prev;

	prev = stack[0].num;
	i = 1;
	while (i < size)
	{
		if (prev > stack[i].num)
			return (0);
		prev = stack[i].num;
		i++;
	}
	return (1);
}
