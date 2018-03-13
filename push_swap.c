/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/13 16:20:36 by dmelnyk          ###   ########.fr       */
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
	int		index;
	int		steps;
	int		tmp;

	stacks.b = (int*)malloc(sizeof(int) * ac - 1);
	stacks.a = get_stack(ac - 1, av);
	stacks.size_a = ac - 1;
	stacks.size_b = 0;
	if (stacks.size_a > 1 && stacks.a[0] > stacks.a[1])
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
//		print_stacks(stacks);
		if (stacks.size_a > 1 && stacks.a[0] > stacks.a[1])
		{
			swap_int(&stacks.a[0], &stacks.a[1]);
			ft_putendl("sa");
		}
		if (min_index(stacks.a, stacks.size_a) == stacks.size_a - 1)
		{
			shift_down(&stacks.a, stacks.size_a);
			ft_putendl("rra");
		}

		//		printf("is_sort=%d\n", is_sort(stacks.a, stacks.b[0], stacks.size_a));
//		print_stacks(stacks);
		if (stacks.size_b > 0 && is_sort(stacks.a, stacks.b[0], stacks.size_a))
			break ;
		index = find_index_in_b(stacks.a[0], stacks.b, stacks.size_b);
//		printf("index=%d\n", index);
		if (index != 0)
		{
			tmp = stacks.size_b - index;
			steps = tmp + 1;
//			printf("tmp=%d\n", tmp);
			if (tmp <= index)
			{
//				printf("index=%d\n", index);
				while (tmp)
				{
					shift_down(&stacks.b, stacks.size_b);
					ft_putendl("rrb");
					tmp--;
				}
			}
/* ????		else if (index != 1)
			{
				while (tmp)
				{
					shift_up(&stacks.b, stacks.size_b);
					ft_putendl("rb");
					tmp--;
				}
				steps *= -1;
			}*/
		}
/*		while (1)
		{
			if (stacks.a[0] < stacks.b[0] && stacks.a[0] > stacks.b[stacks.size_b - 1])
			{
//				printf("test %d\n", stacks.a[0]);
				shift_up(&stacks.b, stacks.size_b);
				ft_putendl("rb");
				steps++;
			}
			else
				break ;
		}*/
		push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
		ft_putendl("pb");
		if (steps != 0)
		{
			if (steps > 0)
				while (steps != 0)
				{
					shift_up(&stacks.b, stacks.size_b);
					ft_putendl("rb");
					steps--;
				}
			if (steps < 0)
			{
				if (stacks.size_b > 1 && index == 1)
				{
					swap_int(&stacks.b[0], &stacks.b[1]);
					ft_putendl("sb");
					steps = 0;
				}
				else
				{
					steps *= -1;
		/* ????		while (steps != 0)
					{
						shift_down(&stacks.b, stacks.size_b);
						ft_putendl("rrb");
						steps--;
					}*/
				}
			}
		}
		if (stacks.size_b > 1)
		{
//			print_stacks(stacks);
			if (stacks.b[0] < stacks.b[1])
			{
				if (stacks.b[0] < stacks.b[stacks.size_b - 1])
				{
					shift_up(&stacks.b, stacks.size_b);
					ft_putendl("rb");
				}
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
