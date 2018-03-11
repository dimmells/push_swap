/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:10:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/11 15:45:00 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include "src/libft/libft.h"
# include "src/gnl/get_next_line.h"

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
}				t_stack;

void			swap_int(int *a, int *b);
void			push_to_top(int **a, int **b, int *size_a, int *size_b);
void			shift_up(int **stack, int size);
void			shift_down(int **stack, int size);
void			ft_int_del(int **integer);

#endif
