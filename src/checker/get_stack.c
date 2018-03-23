/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:40:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:49:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			*get_stack(int ac, char **av, int begin, t_flag flags)
{
	int		*stack;
	int		i;

	stack = (int*)malloc(sizeof(int) * ac);
	i = 0;
	while (i < ac)
	{
		stack[i] = p_atoi(av[begin], flags);
		begin++;
		i++;
	}
	return (stack);
}
