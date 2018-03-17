/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:31:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 13:26:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		shift_up(t_number **stack, int size)
{
	int     i;
	int     top;

	top = (*stack)[0].num;
	i = 0;
	while (i < size - 1)
	{
		(*stack)[i].num = (*stack)[i + 1].num;
		i++;
	}
	(*stack)[size - 1].num = top;
}
