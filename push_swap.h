/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:40:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/16 11:50:05 by dmelnyk          ###   ########.fr       */
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

int					*get_stack(int ac, char **av);
int					is_sort(int *stack, int top_b, int size);
int					find_index_in_b(int top, int *stack, int size);
int					is_top_sort(t_stack stacks);
int					is_stacks_sort(t_stack stacks);
int					find_max_index(int *stack, int size);
void				shift_down(int **stack, int size);
void				print_stacks(t_stack stacks);
void				swap_int(int *a, int *b);
void				push_to_top(int **a, int **b, int *size_a, int *size_b);
void				shift_up(int **stack, int size);

#endif
