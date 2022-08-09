SRC		=	src/op_push_swap.c src/op_rotate_reverse.c src/push_swap.c src/print.c \
			src/ft_split.c src/lists.c src/parsing.c src/utils_1.c src/utils_2.c \
			src/utils_3.c src/utils_4.c src/utils_5.c \

OBJ		= $(SRC:.c=.o)

CC		=		gcc
RM		=		rm -rf
CFLAGS	=		-Wall -Werror -Wextra

NAME	=		push_swap

all: 			$(NAME)

$(NAME):		$(OBJ)
					$(CC) $(OBJ) -o $(NAME)

clean:
					$(RM) $(OBJ)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re