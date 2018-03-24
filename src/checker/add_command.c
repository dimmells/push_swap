/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:28:03 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 14:20:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			add_command(t_command **command_list, char *command)
{
	t_command	*tmp;
	t_command	*new;

	new = (t_command*)malloc(sizeof(t_command));
	new->command = ft_strdup(command);
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
}
