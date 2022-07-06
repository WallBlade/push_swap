SRC		=	push_swap.c push_swap_utils.c utils2.c print.c \
			parsing.c movements.c movements2.c push_swap_lists.c \

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