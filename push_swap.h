/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:40:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/12 16:10:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "src/libft/libft.h"
# include <stdlib.h>

typedef struct		s_stack
{
	int				*a;
	int				*b;
	int				size_a;
	int				size_b;
}					t_stack;

//int					*get_stack(int ac, char **av);
void				shift_down(int **stack, int size);
void				print_stacks(t_stack stacks);
void				swap_int(int *a, int *b);
void				push_to_top(int **a, int **b, int *size_a, int *size_b);
void				shift_up(int **stack, int size);

#endif
