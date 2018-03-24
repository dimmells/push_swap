# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelnyk  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 17:39:30 by dmelnyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../push_swap

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

LIBFT = ../libft/libft.a

SRC =

SRC += add_command.c
SRC += check_dublicates.c
SRC += check_input.c
SRC += get_flags.c
SRC += get_median.c
SRC += get_stack.c
SRC += is_last_group.c
SRC += is_sort.c
SRC += p_atoi.c
SRC += print_command.c
SRC += print_error.c
SRC += print_stacks.c
SRC += print_stat.c
SRC += push_swap.c
SRC += push_to_top.c
SRC += shift_down.c
SRC += shift_up.c
SRC += sort_function.c
SRC += sort_three.c
SRC += swap_int.c
SRC += usage.c

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
