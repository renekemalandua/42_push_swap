# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akemalan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 22:07:11 by akemalan          #+#    #+#              #
#    Updated: 2025/10/04 19:38:53 by akemalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
CHECK = checker

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =  algorithms/ft_sort_three.c\
		algorithms/ft_push_swap.c\
		operations/ft_push.c\
		operations/ft_swap.c\
		operations/ft_rotate.c\
		operations/ft_reverse_rotate.c\
		utils/ft_stack_utils.c\
		utils/ft_mut_split.c\
		utils/ft_error_utils.c\
		init/ft_init_stack.c\
		init/ft_init_node_a_to_b.c\
		init/ft_init_node_b_to_a.c\
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
