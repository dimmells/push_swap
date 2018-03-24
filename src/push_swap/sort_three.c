/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:15:14 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 13:30:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_only_three(t_stack *stacks, t_command **command_list)
{
	while (stacks->size_a <= 3 && !is_sort(stacks->a, stacks->size_a))
	{
		if (stacks->size_a == 2)
		{
			swap_int(&stacks->a[0], &stacks->a[1]);
			add_command(command_list, "sa", *stacks);
		}
		else if (stacks->size_a > 1)
		{
			if (stacks->a[0].num > stacks->a[1].num)
			{
				swap_int(&stacks->a[0], &stacks->a[1]);
				add_command(command_list, "sa", *stacks);
			}
			else
			{
				shift_down(&stacks->a, stacks->size_a);
				add_command(command_list, "rra", *stacks);
			}
		}
	}
}

static void		in_loop(t_stack *stacks, t_command **command_list, int *pa)
{
	if (stacks->a[1].num > stacks->a[0].num &&
			stacks->a[1].num > stacks->a[2].num)
	{
		shift_up(&stacks->a, stacks->size_a);
		add_command(command_list, "ra", *stacks);
		*pa += 1;
	}
	if (stacks->a[0].num > stacks->a[1].num &&
			stacks->a[0].num > stacks->a[2].num)
	{
		swap_int(&stacks->a[0], &stacks->a[1]);
		add_command(command_list, "sa", *stacks);
	}
	if (stacks->a[0].num > stacks->a[1].num)
	{
		swap_int(&stacks->a[0], &stacks->a[1]);
		add_command(command_list, "sa", *stacks);
	}
	if (*pa)
	{
		shift_down(&stacks->a, stacks->size_a);
		add_command(command_list, "rra", *stacks);
		*pa -= 1;
	}
}

void			sort_three(t_stack *stacks, t_command **command_list)
{
	int			pa;

	if (stacks->size_a == 3)
		sort_only_three(stacks, command_list);
	else
	{
		if (stacks->size_a < 3)
			return ;
		pa = 0;
		while (!is_sort(stacks->a, stacks->size_a))
			in_loop(stacks, command_list, &pa);
	}
}
