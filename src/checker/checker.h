/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:10:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 15:15:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef	struct			s_flag
{
	int					e;
}						t_flag;

typedef	struct			s_stack
{
	int					*a;
	int					*b;
	int					size_a;
	int					size_b;
	t_flag				flags;
}						t_stack;

typedef	struct			s_command
{
	char				*command;
	struct s_command	*next;
}						t_command;

void					swap_int(int *a, int *b);
void					push_to_top(int **a, int **b, int *size_a, int *size_b);
void					shift_up(int **stack, int size);
void					shift_down(int **stack, int size);
void					ft_int_del(int **integer);
void					print_error(int error_code, t_flag flags);
void					check_input(char **av, int begin, t_flag flags);
void					check_dublicates(t_stack stacks);
void					usage(void);
void					add_command(t_command **command_list, char *command);
void					check_command(t_command *command_list, t_flag flags);
void					execute(t_stack *stacks, char *command);
int						get_flags(int ac, char **av, t_stack *stacks);
int						*get_stack(int ac, char **av, int begin, t_flag flags);
int						p_atoi(const char *str, t_flag flags);

#endif
