/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/16 13:47:02 by dmelnyk          ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_stack	stacks;
	int		index;
	int		steps;
	int		max;
	int		i;

	stacks.b = (int*)malloc(sizeof(int) * ac - 1);
	stacks.a = get_stack(ac - 1, av);
	stacks.size_a = ac - 1;
	stacks.size_b = 0;
/*	if (stacks.size_a > 1 && stacks.a[0] > stacks.a[1])
	{
???		swap_int(&stacks.a[0], &stacks.a[1]);
		ft_putendl("sa");
	}
*/
//	printf("is_sort=%d\n", is_stacks_sort(stacks));
	while (1)
	{
//		print_stacks(stacks);
		if (is_stacks_sort(stacks) && find_max_index(stacks.b, stacks.size_b) > 1)
			break ;
		if (is_top_sort(stacks))
		{
				shift_down(&stacks.a, stacks.size_a);
				ft_putendl("rra");
		}
		if (!is_top_sort(stacks))
		{
			push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
			ft_putendl("pb");
			if (stacks.size_b > 1 && stacks.b[0] < stacks.b[1])
			{
				if (stacks.size_b == 2)
				{
					swap_int(&stacks.b[0], &stacks.b[1]);
					ft_putendl("sb");
				}
				else
				{
					if (stacks.b[1] - stacks.b[0] < stacks.b[0] - stacks.b[stacks.size_b - 1])
					{
						swap_int(&stacks.b[0], &stacks.b[1]);
						ft_putendl("sb");
					}
					else
					{
						shift_up(&stacks.b, stacks.size_b);
						ft_putendl("rb");
					}
				}
			}
		}
		if (is_top_sort(stacks) && find_max_index(stacks.b, stacks.size_b) == 0)
		{
			push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
			ft_putendl("pa");
		}
	}
	while (stacks.size_b > 0)
	{
//		print_stacks(stacks);
		if (stacks.size_b > 1 && stacks.b[0] < stacks.b[1])
		{
			swap_int(&stacks.b[0], &stacks.b[1]);
			ft_putendl("sb");
		}
		if ((index = find_max_index(stacks.b, stacks.size_b)) == 0)
		{
			push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
			ft_putendl("pa");
		}
		else
		{
			if (stacks.size_b / 2 > index)
			{
				shift_up(&stacks.b, stacks.size_b);
				ft_putendl("rb");
			}
			else
			{
				shift_down(&stacks.b, stacks.size_b);
				ft_putendl("rrb");
			}
		}
	}
//	printf("size=%d\n", stacks.size_a);
//	print_stacks(stacks);	
	return (0);
}
