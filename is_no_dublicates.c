/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_no_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:55:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/15 15:28:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_no_dublicates(int *stack, int size)
{
	int		i;
	int		j;
	int		current;

	i = 0;
	while (i < size)
	{
		current = stack[0];
		j = 0;
		while (j < size)
		{
			if (j == i)
				j++;
			if (current == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
