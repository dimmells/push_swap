/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 15:21:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void sort_three(t_stack *stacks, t_command **command_list)
{
	int		pa;

	if (stacks->size_a < 3)
		return ;
	pa = 0;
	while (!is_sort(stacks->a, stacks->size_a))
	{
		if (stacks->a[1].num > stacks->a[0].num && stacks->a[1].num > stacks->a[2].num)
		{
			shift_up(&stacks->a, stacks->size_a);
			add_command(command_list, "ra", *stacks);
			pa++;
		}
		if (stacks->a[0].num > stacks->a[1].num && stacks->a[0].num > stacks->a[2].num)
		{
			swap_int(&stacks->a[0], &stacks->a[1]);
			add_command(command_list, "sa", *stacks);
		}
		if (stacks->a[0].num > stacks->a[1].num)
		{
			swap_int(&stacks->a[0], &stacks->a[1]);
	        add_command(command_list, "sa", *stacks);
		}
		if (pa)
		{
			shift_down(&stacks->a, stacks->size_a);
			add_command(command_list, "rra", *stacks);
			pa--;
		}
	}
}

static void	sort_only_three(t_stack *stacks, t_command **command_list)
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

int			sort(t_stack stacks, t_command **command_list)
{
	int		i;
	int		mediana;
	int		size;
	int		rb;
	int		pa;

	if (is_sort(stacks.a, stacks.size_a) && stacks.size_b == 0)
		return (1);
	while (stacks.size_a > 3)
	{
		mediana = get_median(stacks, 'a');
		i = 0;
		while (i < stacks.size_a && stacks.a[0].mediana == stacks.a[i].mediana)
			i++;
		size = i / 2;
		while (size)
		{
			if ((stacks.a[0].num < mediana) || (stacks.a[0].num == mediana && size % 2 != 0))
			{
				if (stacks.a[0].num < mediana)
					size--;
				stacks.a[0].mediana = mediana;
				push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
				add_command(command_list, "pb", stacks);
				if (stacks.size_a == 3)
					break ;
			}
			else
			{
				shift_up(&stacks.a, stacks.size_a);
				add_command(command_list, "ra", stacks);
			}
		}
	}
	sort_only_three(&stacks, command_list);
	while (stacks.size_b > 0)
	{
		mediana = stacks.b[0].mediana;
		i = 0;
		while (i < stacks.size_b && stacks.b[i].mediana == mediana)
			i++;
		if (i == -3)
		{
//			print_stacks(stacks);
			while (i)
			{
				push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
				add_command(command_list, "pa", stacks);
				i--;
			}
			sort_three(&stacks, command_list);
			if (stacks.size_b == 0)
				break ;
/*			mediana = stacks.b[0].mediana;
			i = 0;
			while (i < stacks.size_b && stacks.b[i].mediana == mediana)
				i++;*/
		}
		else
		{
			mediana = get_median(stacks, 'b');
			size = i / 2;
			if (i % 2 != 0)
				size++;
			pa = 0;
			rb = 0;
			while (size)
			{
				if (stacks.b[0].num >= mediana)
				{
					if (stacks.b[0].num >= mediana)
						size--;
					stacks.b[0].mediana = mediana;
					push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
					add_command(command_list, "pa", stacks);
					pa++;
				}
				else
				{
					shift_up(&stacks.b, stacks.size_b);
					add_command(command_list, "rb", stacks);
					rb++;
				}
			}
			if (!is_last_group(stacks))
				while (rb > 0)
				{
					shift_down(&stacks.b, stacks.size_b);
					add_command(command_list, "rrb", stacks);
					rb--;
				}
			if (pa > 3)
			{
				while (pa > 3)
				{
					mediana = get_median(stacks, '2');
					i = 0;
					while (i < stacks.size_a && stacks.a[0].mediana == stacks.a[i].mediana)
						i++;
					size = i / 2;
					rb = 0;
					while (size)
					{
						if ((stacks.a[0].num < mediana) || (stacks.a[0].num == mediana && size % 2 != 0))
						{
							if (stacks.a[0].num < mediana)
								size--;
							stacks.a[0].mediana = mediana;
							push_to_top(&stacks.a, &stacks.b, &stacks.size_a, &stacks.size_b);
							add_command(command_list, "pb", stacks);
							pa--;
							if (pa == 3)
								break ;
						}
						else
						{
							shift_up(&stacks.a, stacks.size_a);
							add_command(command_list, "ra", stacks);
							rb++;
						}
					}
					while (rb)
					{
						shift_down(&stacks.a, stacks.size_a);
						add_command(command_list, "rra", stacks);
						rb--;
					}
				}	
			}
			if (stacks.size_a > 2)
				sort_three(&stacks, command_list);
		}
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_stack		stacks;
	int			begin;
	t_command	*command_list;

	if (ac == 1)
		usage();
	begin = get_flags(ac, av, &stacks);
	check_input(ac, av, begin, stacks.flags);
	stacks.b = (t_number*)malloc(sizeof(t_number) * ac - begin);
	stacks.a = get_stack(ac - begin, av, begin, stacks.flags);
	stacks.size_a = ac - begin;
	stacks.size_b = 0;
	check_dublicates(stacks);
	command_list = (t_command*)malloc(sizeof(t_command));
	command_list->command = NULL;
	command_list->next = NULL;
	sort(stacks, &command_list);
//	print_command(stacks, command_list);
	return (0);
}
