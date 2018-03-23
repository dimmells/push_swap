/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:37:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 16:33:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			shift_down(t_number **stack, int size)
{
	int			i;
	int			last_num;
	int			last_mediana;

	last_num = (*stack)[size - 1].num;
	last_mediana = (*stack)[size - 1].mediana;
	i = size - 1;
	while (i > 0)
	{
		(*stack)[i].num = (*stack)[i - 1].num;
		(*stack)[i].mediana = (*stack)[i - 1].mediana;
		i--;
	}
	(*stack)[0].num = last_num;
	(*stack)[0].mediana = last_mediana;
}
