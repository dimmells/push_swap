/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:20:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 11:28:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_top(t_number **a, t_number **b, int *size_a, int *size_b)
{
	int		i;
	int		top;
	int		mediana;

	if (*size_a == 0)
		return ;
	top = (*a)[0].num;
	mediana = (*a)[0].mediana;
	i = -1;
	while (++i < *size_a - 1)
	{
		(*a)[i].num = (*a)[i + 1].num;
		(*a)[i].mediana = (*a)[i + 1].mediana;
	}
	*size_a -= 1;
	i = *size_b;
	while (i > 0)
	{
		(*b)[i].num = (*b)[i - 1].num;
		(*b)[i].mediana = (*b)[i - 1].mediana;
		i--;
	}
	(*b)[0].num = top;
	(*b)[0].mediana = mediana;
	*size_b += 1;
}
