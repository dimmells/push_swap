/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/21 17:14:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void sort_three(t_stack *stacks)
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
			ft_putendl("ra");
			pa++;
		}
		if (stacks->a[0].num > stacks->a[1].num && stacks->a[0].num > stacks->a[2].num)
		{
			swap_int(&stacks->a[0], &stacks->a[1]);
	        ft_putendl("sa");
		}
		if (stacks->a[0].num > stacks->a[1].num)
		{
			swap_int(&stacks->a[0], &stacks->a[1]);
	        ft_putendl("sa");
		}
		if (pa)
		{
			shift_down(&stacks->a, stacks->size_a);
			ft_putendl("rra");
			pa--;
		}
//		print_stacks(*stacks);
	}
}

int			sort(t_stack stacks)
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
				ft_putendl("pb");
				if (stacks.size_a == 3)
					break ;
			}
			else
			{
				shift_up(&stacks.a, stacks.size_a);
				ft_putendl("ra");
			}
		}
	}
	while (stacks.size_a <= 3 && !is_sort(stacks.a, stacks.size_a))
	{
		if (stacks.size_a == 2)
		{
			swap_int(&stacks.a[0], &stacks.a[1]);
			ft_putendl("sa");
		}
		else if (stacks.size_a > 1)
		{
			if (stacks.a[0].num > stacks.a[1].num)
			{
				swap_int(&stacks.a[0], &stacks.a[1]);
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
		while (i < stacks.size_b && stacks.b[i].mediana == mediana)
			i++;
		if (i == -3)
		{
//			print_stacks(stacks);
			while (i)
			{
				push_to_top(&stacks.b, &stacks.a, &stacks.size_b, &stacks.size_a);
				ft_putendl("pa");
				i--;
			}
			sort_three(&stacks);
			if (stacks.size_b == 0)
				break ;
			mediana = stacks.b[0].mediana;
			i = 0;
			while (i < stacks.size_b && stacks.b[i].mediana == mediana)
				i++;
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
					ft_putendl("pa");
					pa++;
				}
				else
				{
					shift_up(&stacks.b, stacks.size_b);
					ft_putendl("rb");
					rb++;
				}
			}
			if (!is_last_group(stacks))
				while (rb > 0)
				{
					shift_down(&stacks.b, stacks.size_b);
					ft_putendl("rrb");
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
							ft_putendl("pb");
							pa--;
							if (pa == 3)
								break ;
						}
						else
						{
							shift_up(&stacks.a, stacks.size_a);
							ft_putendl("ra");
							rb++;
						}
					}
					while (rb)
					{
						shift_down(&stacks.a, stacks.size_a);
						ft_putendl("rra");
						rb--;
					}
				}	
			}
			if (stacks.size_a > 2)
				sort_three(&stacks);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	int		begin;

	if (ac == 1)
		usage();
	begin = get_flags(ac, av, &stacks);
	check_input(ac, av, begin);
	stacks.b = (t_number*)malloc(sizeof(t_number) * ac - begin);
	stacks.a = get_stack(ac - begin, av, begin);
	stacks.size_a = ac - begin;
	stacks.size_b = 0;
	check_dublicates(stacks);
	sort(stacks);
	return (0);
}
