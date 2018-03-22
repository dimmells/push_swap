/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:35:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/22 15:20:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_dublicates(t_stack stacks)
{
	int		i;
	int		j;

	i = 0;
	while (i < stacks.size_a)
	{
		j = 0;
		while (j < stacks.size_a)
		{
			if (j != i)
			{
				if (stacks.a[i].num == stacks.a[j].num)
				{
					print_error(1, stacks.flags);
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
}
