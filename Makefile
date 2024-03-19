SRC=$(shell find ./src -name \*.c -type f -print)
OBJ=$(patsubst ./src/%.c,./obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra
LIBS=-I./libft ./libft/libft.a -lreadline

all:
	make -C libft
	mkdir -p $(shell dirname $(OBJ))
	make $(NAME)

obj/%.o: src/%.c
	cc $(FLAGS) -c -g -o $@ $<

$(NAME): $(OBJ)
	cc $(FLAGS) $(LIBS) $(OBJ) -g -o $@

clean:
	make clean -C libft
	find ./obj -name \*.o -type f -delete

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
