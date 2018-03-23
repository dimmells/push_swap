/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:39:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:48:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			get_flags(int ac, char **av, t_stack *stacks)
{
	int		i;
	int		j;

	stacks->flags.e = 0;
	i = 1;
	while (i < ac)
	{
		j = 1;
		if ((av[i][0] && av[i][0] != '-') || (av[i][0] && av[i][0] == '-' &&
					av[i][1] && ft_isdigit(av[i][1])))
			break ;
		while (av[i][j] && av[i][0] == '-')
		{
			if (j != 0 && av[i][j] == 'e')
				stacks->flags.e = 1;
			else
				usage();
			j++;
		}
		i++;
	}
	return (i);
}
