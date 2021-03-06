/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:12:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 17:57:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		check(t_stack stacks)
{
	int			i;
	int			max;

	if (stacks.size_b == 0)
	{
		max = stacks.a[0];
		i = 1;
		while (i < stacks.size_a)
		{
			if (max < stacks.a[i])
				max = stacks.a[i];
			else
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static void		read_and_execute(t_stack *stacks, t_command **command_list)
{
	char		*command;

	while (get_next_line(0, &command) > 0)
	{
		add_command(command_list, command);
		ft_strdel(&command);
	}
	check_command(*command_list, stacks->flags);
	*command_list = (*command_list)->next;
	while (*command_list)
	{
		execute(stacks, (*command_list)->command);
		(*command_list) = (*command_list)->next;
	}
	if (check(*stacks))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int				main(int ac, char **av)
{
	t_stack		stacks;
	int			begin;
	t_command	*command_list;
	t_command	*head;

	if (ac == 1)
		exit(0);
	begin = get_flags(ac, av, &stacks);
	if (ac - begin == 0)
		usage();
	check_input(av, begin, stacks.flags);
	stacks.b = (int*)malloc(sizeof(int) * ac - begin);
	stacks.a = get_stack(ac - begin, av, begin, stacks.flags);
	stacks.size_a = ac - begin;
	stacks.size_b = 0;
	check_dublicates(stacks);
	command_list = (t_command*)malloc(sizeof(t_command));
	command_list->command = NULL;
	command_list->next = NULL;
	head = command_list;
	read_and_execute(&stacks, &command_list);
	command_list = head;
	return (0);
}
