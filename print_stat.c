/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:52:57 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 16:45:44 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stat(t_command *command_list)
{
	int			rotate;
	int			rev_rotate;
	int			swap;
	int			push;
	int			total;
	t_command	*current;

	ft_putendl(" ************************************************** ");
	ft_putendl("          (╯°□°)╯︵ STATISTICS ¯\\_(ツ)_/¯          ");
	ft_putendl(" -------------------------------------------------- ");
	current = command_list;
	rotate = 0;
	rev_rotate = 0;
	swap = 0;
	push = 0;
	while (current)
	{
		if (ft_strequ(current->command, "ra"))
			rotate++;
		else if (ft_strequ(current->command, "rra"))
			rev_rotate++;
		else if (ft_strequ(current->command, "sa"))
			swap++;
		else if (ft_strequ(current->command, "pa"))
			push++;
		current = current->next;
	}
	ft_putstr("      ra                |                ");
	ft_putnbr(rotate);
	ft_putstr("\n      rra               |                ");
	ft_putnbr(rev_rotate);
	ft_putstr("\n      pa                |                ");
	ft_putnbr(push);
	ft_putstr("\n      sa                |                ");
	ft_putnbr(swap);
	current = command_list;
	rotate = 0;
	rev_rotate = 0;
	swap = 0;
	push = 0;
	total = 0;
	while (current)
	{
		if (ft_strequ(current->command, "rb"))
			rotate++;
		else if (ft_strequ(current->command, "rrb"))
			rev_rotate++;
		else if (ft_strequ(current->command, "sb"))
			swap++;
		else if (ft_strequ(current->command, "pb"))
			push++;
		total++;
		current = current->next;
	}
	ft_putstr("\n      sb                |                ");
	ft_putnbr(swap);
	ft_putstr("\n      ss                |                0");
	ft_putstr("\n      rb                |                ");
	ft_putnbr(rotate);
	ft_putstr("\n      rrb               |                ");
	ft_putnbr(rev_rotate);
	ft_putstr("\n      pb                |                ");
	ft_putnbr(push);
	ft_putstr("\n      rr                |                0");
	ft_putstr("\n      rrr               |                0\n");
	ft_putendl(" ************************************************** ");
	ft_putstr("   (>‘o’)>        TOTAL -----> ");
	ft_putnbr(total - 1);
	ft_putendl("        <('o'<)");
	ft_putendl(" -------------------------------------------------- ");
}
