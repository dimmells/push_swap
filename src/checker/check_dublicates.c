/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:35:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 13:04:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
				if (stacks.a[i] == stacks.a[j])
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
