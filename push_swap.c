/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/18 13:30:35 by dmelnyk          ###   ########.fr       */
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

static void	push_to_a(t_stack *stacks, int index)
{
	if (index == 0)
	{
		push_to_top(&stacks->b, &stacks->a, &stacks->size_b, &stacks->size_a);
		ft_putendl("pa");
	}
	else
	{
		while (find_max_index(stacks->b, stacks->size_b) != 0)
		{
			if (index < stacks->size_b / 2)
			{
				shift_up(&stacks->b, stacks->size_b);
                ft_putendl("rb");
			}
			else
			{
				shift_down(&stacks->b, stacks->size_b);
               	ft_putendl("rrb");
			}
		}
	}
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	int		mediana;
	int		i;
	int		size;
	int		index;
	int		next_index;

	stacks.b = (t_number*)malloc(sizeof(t_number) * ac - 1);
	stacks.a = get_stack(ac - 1, av);
	stacks.size_a = ac - 1;
	stacks.size_b = 0;
	while (stacks.size_a > 3)
	{
		mediana = get_median(stacks, 'a');
		size = stacks.size_a / 2;
		while (size)
		{
			if ((stacks.a[0].num < mediana) || (stacks.a[0].num == mediana && size % 2 != 0))
			{
				if (stacks.a[0].num < mediana)
					size--;
				stacks.a[0].mediana = mediana;
				push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
				ft_putendl("pb");
			}
			else
			{
				shift_up(&stacks.a, stacks.size_a);
				ft_putendl("ra");
			}
		}
	}
	while (!is_sort(stacks.a, stacks.size_a))
	{
		if (stacks.size_a == 2)
		{
			swap_int(&stacks.a[0].num, &stacks.a[1].num);
			ft_putendl("sa");
		}
		else
		{
			if (stacks.a[0].num > stacks.a[1].num)
			{
				swap_int(&stacks.a[0].num, &stacks.a[1].num);
    	        ft_putendl("sa");
			}
			else
			{
				shift_down(&stacks.a, stacks.size_a);
				ft_putendl("rra");
			}
		}
	}
	while (stacks.size_b > 0)
	{
		mediana = stacks.b[0].mediana;
		i = 0;
		while (stacks.b[i].mediana == mediana)
			i++;
		if (i == 2 && stacks.b[0].num < stacks.b[1].num)
		{
			swap_int(&stacks.b[0].num, &stacks.b[1].num);
   	        ft_putendl("sb");
		}
		else
		{
			index = find_max_index(stacks.b, stacks.size_b);
			push_to_a(&stacks, index);
		}
	}
//	print_stacks(stacks);	
	return (0);
}
