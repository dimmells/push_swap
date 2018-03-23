/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:31:54 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:53:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		shift_up(int **stack, int size)
{
	int		i;
	int		top;

	top = (*stack)[0];
	i = 0;
	while (i < size - 1)
	{
		(*stack)[i] = (*stack)[i + 1];
		i++;
	}
	(*stack)[size - 1] = top;
}
