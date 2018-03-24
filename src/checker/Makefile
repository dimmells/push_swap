# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelnyk  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 15:16:26 by dmelnyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../checker

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

LIBFT = ../libft/libft.a

GNL = ../gnl/get_next_line.c

SRC =

SRC += add_command.c
SRC += check_command.c
SRC += check_dublicates.c
SRC += check_input.c
SRC += checker.c
SRC += execute.c
SRC += get_flags.c
SRC += get_stack.c
SRC += p_atoi.c
SRC += print_error.c
SRC += push_to_top.c
SRC += shift_down.c
SRC += shift_up.c
SRC += swap_int.c
SRC += usage.c

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(GNL) $(LIBFT)

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
