SRC=$(shell find ./src -name \*.c -type f -print)
OBJ=$(patsubst ./src/%.c,./obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra
INCLUDES=-I./libft -I/opt/homebrew/Cellar/readline/8.2.10/include
LIBS=./libft/libft.a -L/opt/homebrew/Cellar/readline/8.2.10/lib -lreadline -lhistory

all:
	make -C libft
	mkdir -p $(shell dirname $(OBJ))
	make $(NAME)

obj/%.o: src/%.c
	cc -c $(FLAGS) $(INCLUDES) -g -o $@ $<  # Use the flags and include directories

$(NAME): $(OBJ)
	cc $(OBJ) $(LIBS) $(FLAGS) $(INCLUDES) -g -o $@  # Link with the correct library paths

clean:
	make -C libft clean
	find ./obj -name \*.o -type f -delete

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
