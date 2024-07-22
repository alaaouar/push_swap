NAME	=	push_swap

CHECKER	=	checker

SRC		=	parcing/parcing_1.c \
			parcing/parcing_2.c \
			parcing/parcing_3.c \
			rules/instructions.c \
			rules/rules.c \
			rules/rules2.c \
			rules/rules3.c \
			sources/sort.c \
			utils/utils1.c \
			utils/utils2.c \
			push_swap.c

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

%.o	 : %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -s -C libft/
clean:
		make clean -s -C libft
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME) $(NAME)
		make fclean -s -C libft

re:	fclean all

.PHONY: all clean fclean re