# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 13:57:47 by maperez-          #+#    #+#              #
#    Updated: 2022/09/20 13:57:48 by maperez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = pipex

SRCS   = pipex.c ft_utils.c ft_strutils.c ft_split.c

OBJS   = ${SRCS:.c=.o}

cc     = gcc

CFLAGS = -Wall -Wextra -Werror

RM	   = rm -f

all:   $(NAME)

$(NAME): ${OBJS}
		 ${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re:		fclean all

.PHONY: all, clean, fcelan, re