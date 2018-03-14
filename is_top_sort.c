/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_top_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:33:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/14 14:33:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	find_max(int *a, int *b, int size_a, int size_b)
{
	int		max;
	int		i;

	if (size_a > 0)
		max = a[size_a - 1];
	else
		max = b[size_b - 1];
	if (size_b > 0 && max < b[size_b - 1])
		max = b[size_b - 1];
	return (max);
}

static int	min_in(int *stack, int size, int i)
{
	int		min;
	int		index;

	min = stack[i];
	index = i;
	i++;
	while (i < size)
	{
		if (min > stack[i])
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	sort(int *stack, int size)
{
	int 	i;
	int		min_index;
	int		tmp;
/*check leaks*/
	i = 0;
	while (i < size)
	{
		min_index = min_in(stack, size, i);
		if (min_index != i)
		{
			tmp = stack[i];
			stack[i] = stack[min_index];
			stack[min_index] = tmp;
		}
		i++;
	}
}

static int	*copy(int *a, int *b, int size_a, int size_b)
{
	int		i;
	int		*ret;

	i = 0;
	ret = (int*)malloc(sizeof(int) * size_a + size_b);
	while (i < size_a)
	{
		ret[i] = a[i];
		i++;
	}
	i = 0;
	while (i < size_b)
	{
		ret[i + size_a] = b[i];
		i++;
	}
	return (ret);
}

int			is_top_sort(t_stack stacks)
{
	int		max;
	int		size;
	int		i;
	int		*a;

	a = copy(stacks.a, stacks.b, stacks.size_a, stacks.size_b);
	size = stacks.size_a + stacks.size_b;
	sort(a, size);
	max = a[size - 1];
	i = 0;
	while (i < size)
	{
		if (max == stacks.a[i])
			break ;
		i++;
	}
	while (i >= 0)
	{
		if (stacks.a[i] != a[size - 1])
			return (0);
		size--;
		i--;
	}
	return (1);
}
