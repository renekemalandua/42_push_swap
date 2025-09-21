# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akemalan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 22:07:11 by akemalan          #+#    #+#              #
#    Updated: 2025/08/29 09:55:17 by akemalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCS = \
	ft_read_list_utils.c ft_write_list_utils.c ft_args_utils.c ft_stack_index_utils.c \
	ft_stack_move_utils.c ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_radix_sort.c \
	ft_simple_sort.c main.c
	
OBJS = $(SRCS:.c=.o)

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