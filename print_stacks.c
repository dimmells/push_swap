/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:15:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/12 12:33:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void		print_stacks(t_stack stacks)
{
	int     i;

	printf("STACK A\n");
	i = 0;
	while (i < stacks.size_a)
	{
		printf("%d\n", stacks.a[i]);
		i++;
	}
	printf("---\nSTACK B\n");
	i = 0;
	while (i < stacks.size_b)
	{
		printf("%d\n", stacks.b[i]);
		i++;
	}
	printf("---\n");
}
