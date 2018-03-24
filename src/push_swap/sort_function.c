/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:25:07 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 17:36:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_to_b(t_stack *stacks, t_command **command_list,
		int size, int mediana)
{
	while (size)
	{
		if ((stacks->a[0].num < mediana))
		{
			size--;
			stacks->a[0].mediana = mediana;
			push_to_top(&stacks->a, &stacks->b,
					&stacks->size_a, &stacks->size_b);
			add_command(command_list, "pb", *stacks);
			if (stacks->size_a == 3)
				break ;
		}
		else
		{
			shift_up(&stacks->a, stacks->size_a);
			add_command(command_list, "ra", *stacks);
		}
	}
}

int				push_to_a(t_stack *stacks, t_command **command_list,
		int *pa, int size)
{
	int			rb;
	int			mediana;

	mediana = get_median(*stacks, 'b');
	rb = 0;
	while (size)
	{
		if (stacks->b[0].num >= mediana)
		{
			if (stacks->b[0].num >= mediana)
				size--;
			stacks->b[0].mediana = mediana;
			push_to_top(&stacks->b, &stacks->a, &stacks->size_b,
					&stacks->size_a);
			add_command(command_list, "pa", *stacks);
			*pa += 1;
		}
		else
		{
			shift_up(&stacks->b, stacks->size_b);
			add_command(command_list, "rb", *stacks);
			rb++;
		}
	}
	return (rb);
}

int				push_back_to_b(t_stack *st, t_command **command_list,
		int *pa, int size)
{
	int			mediana;
	int			rb;

	rb = 0;
	mediana = get_median(*st, '2');
	while (size)
	{
		if ((st->a[0].num < mediana))
		{
			size--;
			st->a[0].mediana = mediana;
			push_to_top(&st->a, &st->b, &st->size_a, &st->size_b);
			add_command(command_list, "pb", *st);
			*pa -= 1;
			if (*pa == 3)
				break ;
		}
		else
		{
			shift_up(&st->a, st->size_a);
			add_command(command_list, "ra", *st);
			rb++;
		}
	}
	return (rb);
}

void			if_pa_bigger_three(t_stack *st,
		t_command **command_list, int pa)
{
	int			rb;
	int			mediana;
	int			i;
	int			size;

	if (pa > 3)
	{
		while (pa > 3)
		{
			mediana = get_median(*st, '2');
			i = 0;
			while (i < st->size_a && st->a[0].mediana == st->a[i].mediana)
				i++;
			size = i / 2;
			rb = push_back_to_b(st, command_list, &pa, size);
			while (rb)
			{
				shift_down(&st->a, st->size_a);
				add_command(command_list, "rra", *st);
				rb--;
			}
		}
	}
	if (st->size_a > 2)
		sort_three(st, command_list);
}

void			while_b_not_empty(t_stack *stacks, t_command **command_list)
{
	int			mediana;
	int			size;
	int			i;
	int			pa;
	int			rb;

	while (stacks->size_b > 0)
	{
		mediana = stacks->b[0].mediana;
		i = 0;
		while (i < stacks->size_b && stacks->b[i].mediana == mediana)
			i++;
		size = i / 2;
		if (i % 2 != 0)
			size++;
		pa = 0;
		rb = push_to_a(stacks, command_list, &pa, size);
		if (!is_last_group(*stacks))
			while (rb--)
			{
				shift_down(&stacks->b, stacks->size_b);
				add_command(command_list, "rrb", *stacks);
			}
		if_pa_bigger_three(stacks, command_list, pa);
	}
}
