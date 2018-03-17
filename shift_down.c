/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:37:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/17 14:31:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			shift_down(t_number **stack, int size)
{
	int			i;
	t_number	last;

	last = (*stack)[size - 1];
	i = size;
    while (i > 0)
    {
		(*stack)[i] = (*stack)[i - 1];
		i--;
	}
	(*stack)[0] = last;
}
