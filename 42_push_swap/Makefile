NAME	= push_swap
BNAME	= checker

SRCS	= src/utils/ft_order.c src/utils/ft_manage_memory.c \
			src/libft_utils/ft_libft_utils.c src/libft_utils/ft_split.c \
			src/utils/ft_print_struct.c src/utils/ft_utils.c \
			operations/ft_push.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_swap.c src/push_swap.c 

BSRCS	= src/libft_utils/ft_libft_utils.c src/libft_utils/ft_split.c src/utils/ft_manage_memory.c \
			src/utils/ft_order.c src/utils/ft_print_struct.c src/utils/ft_utils.c \
			operations/ft_push.c operations/ft_reverse_rotate.c operations/ft_rotate.c operations/ft_swap.c \
			src/get_next_line/get_next_line_utils.c src/get_next_line/get_next_line.c bonus/checker.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CC		= gcc

LIBRARIES = libraries/

CFLAGS	= -Wall -Werror -Wextra -I ${LIBRARIES}

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME} ${BNAME}

bonus:		${BOBJS}
			${CC} ${BOBJS} -o ${BNAME}

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
