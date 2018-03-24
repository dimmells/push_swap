/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:52:57 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 13:10:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		count_cont(int commands[], t_command *command_list, int total)
{
	t_command	*current;

	current = command_list;
	while (current)
	{
		if (ft_strequ(current->command, "pa"))
			commands[3]++;
		else if (ft_strequ(current->command, "pb"))
			commands[4]++;
		else if (ft_strequ(current->command, "ra"))
			commands[5]++;
		else if (ft_strequ(current->command, "rb"))
			commands[6]++;
		else if (ft_strequ(current->command, "rr"))
			commands[7]++;
		else if (ft_strequ(current->command, "rra"))
			commands[8]++;
		else if (ft_strequ(current->command, "rrb"))
			commands[9]++;
		else if (ft_strequ(current->command, "rrr"))
			commands[10]++;
		total++;
		current = current->next;
	}
	return (total);
}

static int		count(int commands[], t_command *command_list, int total)
{
	t_command	*current;
	int			i;

	i = 0;
	while (i < 11)
	{
		commands[i] = 0;
		i++;
	}
	current = command_list;
	total = 0;
	while (current)
	{
		if (ft_strequ(current->command, "sa"))
			commands[0]++;
		else if (ft_strequ(current->command, "sb"))
			commands[1]++;
		else if (ft_strequ(current->command, "ss"))
			commands[2]++;
		total++;
		current = current->next;
	}
	count_cont(commands, command_list, total);
	return (total);
}

static void		print_info_end(int commands[], int total)
{
	ft_putnbr(commands[6]);
	ft_putstr("\n      rr                |                ");
	ft_putnbr(commands[7]);
	ft_putstr("\n      rra               |                ");
	ft_putnbr(commands[8]);
	ft_putstr("\n      rrb               |                ");
	ft_putnbr(commands[9]);
	ft_putstr("\n      rrr               |                ");
	ft_putnbr(commands[10]);
	ft_putendl("\n\033[0;36m ********************************************** ");
	ft_putstr("  \033[0;33m(>‘o’)>      \033[0;32mTOTAL ");
	ft_putstr("\033[0;36m-----> \033[0;32m");
	ft_putnbr(total - 1);
	ft_putendl("       \033[0;33m<('o'<)");
	ft_putendl("\033[0;36m ---------------------------------------------- ");
}

static void		print_info(int commands[], t_command *command_list)
{
	int			total;

	total = count(commands, command_list, total);
	ft_putendl("\033[0;36m ********************************************** ");
	ft_putstr("         \033[0;33m (╯°□°)╯︵ \033[0;36mSTATISTICS \033[0;33m");
	ft_putendl("¯\\_(ツ)_/¯          ");
	ft_putendl("\033[0;36m ---------------------------------------------- ");
	ft_putstr("\033[0;32m      sa                |                ");
	ft_putnbr(commands[0]);
	ft_putstr("\n      sb                |                ");
	ft_putnbr(commands[1]);
	ft_putstr("\n      ss                |                ");
	ft_putnbr(commands[2]);
	ft_putstr("\n      pa                |                ");
	ft_putnbr(commands[3]);
	ft_putstr("\n      pb                |                ");
	ft_putnbr(commands[4]);
	ft_putstr("\n      ra                |                ");
	ft_putnbr(commands[5]);
	ft_putstr("\n      rb                |                ");
	print_info_end(commands, total);
}

void			print_stat(t_command *command_list)
{
	int			commands[11];
	int			i;

	print_info(commands, command_list);
	ft_putstr("\033[0m");
}
