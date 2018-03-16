/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:37:10 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/16 11:49:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_max_index(int *stack, int size)
{
	int		i;
	int		max;
	int		index;

	max = stack[0];
	index = 0;
	i = 1;
	while (i < size)
	{
		if (max < stack[i])
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
