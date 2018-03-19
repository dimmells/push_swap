/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:31:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/19 13:56:16 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		shift_up(t_number **stack, int size)
{
	int     i;
	int		top_num;
	int		top_mediana;

	top_num = (*stack)[0].num;
	top_mediana = (*stack)[0].mediana;
	i = 0;
	while (i < size - 1)
	{
		(*stack)[i].num = (*stack)[i + 1].num;
		(*stack)[i].mediana = (*stack)[i + 1].mediana;
		i++;
	}
	(*stack)[size - 1].num = top_num;
	(*stack)[size - 1].mediana = top_mediana;
}
