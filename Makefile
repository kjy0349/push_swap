# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 11:06:24 by jeykim            #+#    #+#              #
#    Updated: 2022/11/04 19:34:03 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= get_idx.c helps.c make_array.c push_swap.c rotate.c set_position.c sort.c stack.c swap_func.c swap_rfunc.c
OBJECT	= ${SRC:.c=.o}
INCS	= .

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJECT}
	${CC} ${CFLAGS} ${OBJECT} -L./libft -lft -o ${NAME}

all : ${NAME}

clean :
	rm -f ${OBJECT}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re .c.o