# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 11:06:24 by jeykim            #+#    #+#              #
#    Updated: 2022/11/05 21:40:41 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= get_idx.c helps.c make_array.c push_swap.c rotate.c set_position.c sort.c stack.c swap_func.c swap_rfunc.c help2.c
SRC_BONUS = push_swap_bonus.c help2.c make_array.c stack.c sort.c helps.c get_idx.c swap_func_b.c get_next_line.c get_next_line_utils.c rotate.c swap_rfunc_b.c set_position.c
OBJECT	= ${SRC:.c=.o}
OBJECT_BONUS = ${SRC_BONUS:.c=.o}
INCS	= .

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJECT}
	make -C ./libft all
	${CC} ${CFLAGS} ${OBJECT} -L./libft -lft -o ${NAME}

all : ${NAME}

clean :
	rm -f ${OBJECT} ${OBJECT_BONUS}
	make -C ./libft fclean

fclean : clean
	rm -f ${NAME} ${BONUS}

bonus :
	make -C ./libft all
	make ${BONUS}

${BONUS} : ${OBJECT_BONUS}
	${CC} ${CFLAGS} ${OBJECT_BONUS} -L./libft -lft -o ${BONUS}

re : fclean all

.PHONY : all clean fclean re .c.o bonus
