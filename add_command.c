/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:28:03 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 15:27:09 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_command(t_command **command_list, char *command, t_stack stacks)
{
	t_command	*tmp;
	t_command	*new;

	new = (t_command*)malloc(sizeof(t_command));
	new->command = command;
	new->next = NULL;
	if (*command_list)
	{
		tmp = *command_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		tmp = new;
	print_command(stacks, command);
}
