/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:05:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/14 12:06:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  *get_stack(int ac, char **av)
{
	int     *stack;
	int     i;

	stack = (int*)malloc(sizeof(int) * ac);
	i = 0;
	while (i < ac)
	{
		stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (stack);
}
