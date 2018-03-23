/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:14:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:48:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		swap_first(t_stack *stacks, char *command)
{
	if (stacks->size_a > 1 && (ft_strequ("sa", command) ||
				ft_strequ("ss", command)))
		swap_int(&stacks->a[0], &stacks->a[1]);
	if (stacks->size_b > 1 && (ft_strequ("sb", command) ||
				ft_strequ("ss", command)))
		swap_int(&stacks->b[0], &stacks->b[1]);
}

static void		push_top(t_stack *stacks, char *command)
{
	if (stacks->size_b > 0 && ft_strequ("pa", command))
		push_to_top(&stacks->b, &stacks->a, &stacks->size_b, &stacks->size_a);
	else if (stacks->size_a > 0 && ft_strequ("pb", command))
		push_to_top(&stacks->a, &stacks->b, &stacks->size_a, &stacks->size_b);
}

static void		shift(t_stack *stacks, char *command)
{
	if (stacks->size_a > 1 && (ft_strequ("ra", command) ||
				ft_strequ("rr", command)))
		shift_up(&stacks->a, stacks->size_a);
	if (stacks->size_b > 1 && (ft_strequ("rb", command) ||
				ft_strequ("rr", command)))
		shift_up(&stacks->b, stacks->size_b);
	if (stacks->size_a > 1 && (ft_strequ("rra", command) ||
				ft_strequ("rrr", command)))
		shift_down(&stacks->a, stacks->size_a);
	if (stacks->size_b > 1 && (ft_strequ("rrb", command) ||
				ft_strequ("rrr", command)))
		shift_down(&stacks->b, stacks->size_b);
}

void			execute(t_stack *stacks, char *command)
{
	if (ft_strequ("sa", command) || ft_strequ("sb", command) ||
			ft_strequ("ss", command))
		swap_first(stacks, command);
	else if (ft_strequ("pa", command) || ft_strequ("pb", command))
		push_top(stacks, command);
	else if (ft_strequ("ra", command) || ft_strequ("rb", command) ||
			ft_strequ("rr", command))
		shift(stacks, command);
	else if (ft_strequ("rra", command) || ft_strequ("rrb", command) ||
			ft_strequ("rrr", command))
		shift(stacks, command);
}
