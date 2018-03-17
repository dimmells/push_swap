/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:37:29 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 14:08:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int  min_in(int *stack, int size, int i)
{
    int     min;
    int     index;

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

static void sort(int *stack, int size)
{
    int     i;
    int     min_index;
    int     tmp;
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

static int  *copy(t_number *stack, int size)
{
    int     i;
    int     *ret;

    i = 0;
    ret = (int*)malloc(sizeof(int) * size);
    while (i < size)
    {
        ret[i] = stack[i].num;
        i++;
    }
    return (ret);
}

int			get_median(t_stack stacks, char stack)
{
	int		*a;
	if (stack == 'a')
	{
		a = copy(stacks.a, stacks.size_a);
		sort(a, stacks.size_a);
		return (a[stacks.size_a / 2]);
	}
	return (0);
}
