# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akemalan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 22:07:11 by akemalan          #+#    #+#              #
#    Updated: 2025/09/26 08:46:39 by akemalan         ###   ########.fr        #
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
		algorithms/ft_chunk_sort.c\
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

# ~~~~~~ STACKS ~~~~~~
STACK5   = 3 1 5 2 4
STACK25  = 12 5 23 7 18 3 15 20 2 8 14 6 11 4 22 9 21 13 10 25 1 16 24 17 19
STACK100 = 437 21 88 56 312 499 205 128 392 14 76 254 63 412 377 98 5 333 120 450 39 271 300 48 260 110 355 421 67 499 246 168 94 219 185 144 383 201 82 356 266 444 317 278 402 17 457 350 389 143 322 62 370 47 174 208 367 280 229 375 266 332 136 200 360 117 307 163 241 34 250 411 99 420 454 396 46 369 342 213 142 455 156 304 360 191 318 311 249 392 278 150 487 242 215 399 182 369 151 307
STACK500 = $(shell jot -r 500 1 5000)

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

run5:
	./$(NAME) $(STACK5) | ./$(CHECK) $(STACK5)

run25:
	./$(NAME) $(STACK25) | ./$(CHECK) $(STACK25)

run100:
	./$(NAME) $(STACK100) | ./$(CHECK) $(STACK100)

run500:
	./$(NAME) $(STACK500) | ./$(CHECK) $(STACK500)

clean:
	${MAKE} -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
