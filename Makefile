# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akemalan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 22:07:11 by akemalan          #+#    #+#              #
#    Updated: 2025/09/23 08:54:37 by akemalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
CHECK = checker

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =  algorithms/ft_radix_sort.c\
		algorithms/ft_simple_sort.c\
		instructions/ft_push.c\
		instructions/ft_swap.c\
		instructions/ft_rotate.c\
		instructions/ft_reverse_rotate.c\
		utils/ft_args_utils.c\
		utils/ft_read_list_utils.c\
		utils/ft_write_list_utils.c\
		utils/ft_stack_index_utils.c\
		utils/ft_stack_move_utils.c\
		main.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
	${MAKE} -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
