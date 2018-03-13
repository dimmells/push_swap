/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:54:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/13 14:28:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_sort(int *stack, int top_b, int size)
{
	int		i;
	int		prev;

	prev = stack[0];
	if (prev < top_b)
		return (0);
	i = 1;
	while (i < size)
	{
		if (prev > stack[i])
			return (0);
		prev = stack[i];
		i++;
	}
	return (1);
}
