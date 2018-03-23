/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:04:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 14:08:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_command(t_stack stacks, char *command)
{
	if (stacks.flags.c == 1 && stacks.flags.a == 0
			&& is_sort(stacks.a, stacks.size_a) && stacks.size_b == 0)
	{
		ft_putstr("\x1b[35m");
		ft_putendl(command);
		ft_putstr("\033[0m");
	}
	else if (stacks.flags.c == 1 && stacks.flags.a == 1)
	{
		ft_putstr("\x1b[35m");
		ft_putendl(command);
		ft_putstr("\033[0m");
	}
	else
		ft_putendl(command);
	if (stacks.flags.v == 1 && stacks.flags.p == 1 &&
			is_sort(stacks.a, stacks.size_a) && stacks.size_b == 0)
	{
		ft_putstr("\033[0;32m");
		print_stacks(stacks);
		ft_putstr("\033[0m");
	}
	else if (stacks.flags.v == 1 && stacks.flags.p == 1)
	{
		ft_putstr("\033[0;31m");
		print_stacks(stacks);
		ft_putstr("\033[0m");
	}
	else if (stacks.flags.v == 1)
		print_stacks(stacks);
}
