/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:02:03 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/19 15:10:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_last_group(t_stack stacks)
{
	int		i;
	int		mediana;

	mediana = stacks.b[0].mediana;
	i = 1;
	while (i < stacks.size_b)
	{
		if (mediana != stacks.b[i].mediana)
			return (0);
		i++;
	}
	return (1);
}
