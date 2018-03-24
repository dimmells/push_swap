/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:38:38 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 17:56:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sort(t_stack stacks, t_command **command_list)
{
	int			i;
	int			size;
	int			mediana;

	while (stacks.size_a > 3)
	{
		mediana = get_median(stacks, 'a');
		i = 0;
		while (i < stacks.size_a && stacks.a[0].mediana == stacks.a[i].mediana)
			i++;
		size = i / 2;
		push_to_b(&stacks, command_list, size, mediana);
	}
	sort_three(&stacks, command_list);
	while_b_not_empty(&stacks, command_list);
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
	if (ac - begin == 0)
		usage();
	check_input(av, begin, stacks.flags);
	stacks.b = (t_number*)malloc(sizeof(t_number) * ac - begin);
	stacks.a = get_stack(ac - begin, av, begin, stacks.flags);
	stacks.size_a = ac - begin;
	stacks.size_b = 0;
	check_dublicates(stacks);
	command_list = (t_command*)malloc(sizeof(t_command));
	command_list->command = NULL;
	command_list->next = NULL;
	if (is_sort(stacks.a, stacks.size_a) && stacks.size_b == 0)
		return (1);
	sort(stacks, &command_list);
	if (stacks.flags.s == 1)
		print_stat(command_list);
	return (0);
}
