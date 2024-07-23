NAME    = push_swap

SRC     = main.c \
          rules/instructions.c \
          rules/rules.c \
          rules/rules2.c \
          rules/rules3.c \
          ft_split.c \
          more_utils.c \
          sort_big.c \
          sort_small.c \
          sort.c \
          utils.c \
          utils_1.c \
		  utils_2.c \

CC      = cc
CFLAGS  = -Wall -Werror -Wextra

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
