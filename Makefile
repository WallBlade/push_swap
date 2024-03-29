SRC		=	src/op_push_swap.c src/op_rotate_reverse.c src/push_swap.c src/algo.c \
			src/lists.c src/parsing.c src/utils_1.c src/utils_2.c src/utils_3.c \
			src/cost.c src/median.c \

OBJ		= $(SRC:.c=.o)

CC		=		cc
RM		=		rm -rf
CFLAGS	=		-Wall -Werror -Wextra -I./includes

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