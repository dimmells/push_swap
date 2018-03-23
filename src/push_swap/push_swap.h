/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:40:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 13:28:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct			s_flag
{
	int					c;
	int					v;
	int					a;
	int					e;
	int					p;
	int					s;
}						t_flag;

typedef struct			s_number
{
	int					num;
	int					mediana;
}						t_number;

typedef struct			s_stack
{
	t_number			*a;
	t_number			*b;
	int					size_a;
	int					size_b;
	t_flag				flags;
}						t_stack;

typedef struct			s_command
{
	char				*command;
	struct s_command	*next;
}						t_command;

t_number				*get_stack(int ac, char **av, int begin, t_flag flags);
int						is_sort(t_number *stack, int size);
int						find_index_in_b(int top, int *stack, int size);
int						is_top_sort(t_stack stacks);
int						is_stacks_sort(t_stack stacks);
int						find_max_index(t_number *stack, int size);
int						get_median(t_stack stacks, char stack);
int						is_last_group(t_stack stacks);
int						p_atoi(const char *str, t_flag flags);
int						get_flags(int ac, char **av, t_stack *stacks);
void					shift_down(t_number **stack, int size);
void					print_stacks(t_stack stacks);
void					swap_int(t_number *a, t_number *b);
void					push_to_top(t_number **a, t_number **b, int *size_a, int *size_b);
void					shift_up(t_number **stack, int size);
void					check_dublicates(t_stack stacks);
void					check_input(int ac, char **av, int begin, t_flag flags);
void					usage(void);
void					print_command(t_stack stacks, char *command);
void					add_command(t_command **command_list, char *command, t_stack stacks);
void					print_error(int error_code, t_flag flags);
void					print_stat(t_command *command_list);

#endif
