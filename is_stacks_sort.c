/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stacks_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:55:07 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/15 13:07:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_stacks_sort(t_stack stacks)
{
	int		i;
	int		prev;

	prev = stacks.a[stacks.size_a - 1];
	i = stacks.size_a - 2;
	while (i >= 0)
	{
		if (prev < stacks.a[i])
			return (0);
		i--;
	}
	if (stacks.size_b > 1)
	{
		prev = stacks.b[0];
		i = 1;
		while (i < stacks.size_b)
		{
			if (prev < stacks.b[i])
				return (0);
			i++;
		}
	}
	return (1);
}

