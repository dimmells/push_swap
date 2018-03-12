/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/12 13:50:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	min_index(int *stack, int size)
{
	int		i;
	int		min;
	int		index;

	min = stack[0];
	index = 0;
	i = 1;
	while(i < size)
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

static int  *get_stack(int ac, char **av)
{
    int     *stack;
    int     i;

    stack = (int*)malloc(sizeof(int) * ac);
    i = 0;
    while (i < ac)
    {
        stack[i] = ft_atoi(av[i + 1]);
        i++;
    }
    return (stack);
}

int			main(int ac, char **av)
{
	t_stack	stacks;

	stacks.b = (int*)malloc(sizeof(int) * ac - 1);
	stacks.a = get_stack(ac - 1, av);
	stacks.size_a = ac - 1;
	stacks.size_b = 0;
	if (stacks.a[0] > stacks.a[1])
	{
		swap_int(&stacks.a[0], &stacks.a[1]);
		ft_putendl("sa");
	}
//	if (min_index(stacks.a, stacks.size_a) == stacks.size_a - 1)
//	{
//		shift_down(&stacks.a, stacks.size_a);
//		ft_putendl("rra");
//	}
	while (stacks.size_a > 0)
	{
		if (stacks.size_a > 1 && stacks.a[0] > stacks.a[1])
		{
			swap_int(&stacks.a[0], &stacks.a[1]);
			ft_putendl("sa");
		}
		push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
		ft_putendl("pb");
		if (stacks.size_b > 1)
		{
//			printf("size_b=%d\n", stacks.size_b);
//			print_stacks(stacks);
			if (stacks.b[0] < stacks.b[1])
			{
//				printf("NUM %d\nSIZE %d\n\n",stacks.b[0], stacks.size_b - 1);
				if (stacks.b[0] < stacks.b[stacks.size_b - 1])
				{
					printf("if\n");
					shift_up(&stacks.b, stacks.size_b);
					ft_putendl("rb");
				}
			//	else
			//	{
//
//				}
			}
		}
	}
	while (stacks.size_b > 0)
	{
		push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
		ft_putendl("pa");
	}
//	print_stacks(stacks);
	return (0);
}
