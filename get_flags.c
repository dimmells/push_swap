/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:39:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 14:02:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_flags(int ac, char **av, t_stack *stacks)
{
	int		i;
	int		j;

	stacks->flags.c = 0;
	stacks->flags.v = 0;
	stacks->flags.a = 0;
	stacks->flags.e = 0;
	stacks->flags.p = 0;
	i = 1;
	while (i < ac)
	{
		j = 1;
		if (av[i][0] && av[i][0] != '-')
			break ;
		while (av[i][j] && av[i][0] == '-')
		{
			if (j != 0 && av[i][j] == 'c')
				stacks->flags.c = 1;
			else if (j != 0 && av[i][j] == 'v')
				stacks->flags.v = 1;
			else if (j != 0 && av[i][j] == 'a')
				stacks->flags.a = 1;
			else if (j != 0 && av[i][j] == 'e')
				stacks->flags.e = 1;
			else if (j != 0 && av[i][j] == 'p')
				stacks->flags.p = 1;
			else
				usage();
			j++;
		}
		i++;
	}
	return (i);
}
