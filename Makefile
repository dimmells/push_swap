# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelnyk  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/03/24 15:31:21 by dmelnyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = src/libft

PATH_CHECKER = src/checker

PATH_PUSH_SWAP = src/push_swap

all:
	@make -C $(PATH_LIBFT)
	@make -C $(PATH_CHECKER)
	@make -C $(PATH_PUSH_SWAP)

clean:
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_CHECKER)
	@make clean -C $(PATH_PUSH_SWAP)

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@make fclean -C $(PATH_CHECKER)
	@make fclean -C $(PATH_PUSH_SWAP)

re: fclean all
