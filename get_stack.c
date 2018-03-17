/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:05:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 12:33:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number		*get_stack(int ac, char **av)
{
	t_number	*stack;
	int			i;

	stack = (t_number*)malloc(sizeof(t_number) * ac);
	i = 0;
	while (i < ac)
	{
		stack[i].num = ft_atoi(av[i + 1]);
		stack[i].mediana = 0;
		i++;
	}
	return (stack);
}
