NAME    = push_swap

SRC     = main.c \
          rules/instructions.c \
          rules/rules.c \
          rules/rules2.c \
          rules/rules3.c \
          sorting/sort_big.c \
          sorting/sort_small.c \
          sorting/sort.c \
          utils/ft_split.c \
          utils/more_utils.c \
          utils/utils.c \
          utils/utils_1.c \
		  utils/utils_2.c \

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -fsanitize=address -g3

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
