/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:49:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:02:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		check_command(t_command *command_list, t_flag flags)
{
	command_list = command_list->next;
	while (command_list)
	{
		if (!ft_strequ("sa", command_list->command) &&
				!ft_strequ("sb", command_list->command) &&
				!ft_strequ("ss", command_list->command) &&
				!ft_strequ("pa", command_list->command) &&
				!ft_strequ("pb", command_list->command) &&
				!ft_strequ("ra", command_list->command) &&
				!ft_strequ("rb", command_list->command) &&
				!ft_strequ("rr", command_list->command) &&
				!ft_strequ("rra", command_list->command) &&
				!ft_strequ("rrb", command_list->command) &&
				!ft_strequ("rrr", command_list->command))
		{
			print_error(4, flags);
			exit(0);
		}
		command_list = command_list->next;
	}
}
