NAME = philo
CC = cc
# CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	utils_1.c \
	init_data.c \
	monitoring.c \
	frees.c \
	checkers.c \
	forks.c

OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRC)


fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re