/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:43:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/13 14:56:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_index_in_b(int top, int *stack, int size)
{
	int		i;
	int		index;

	if (size > 0 && top > stack[0])
		return (0);
	if (size > 0 && top < stack[size - 1])
		return (size);
	index = 0;
	i = 0;
	while (i < size - 1)
	{
		if (top < stack[i] && top > stack[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}
