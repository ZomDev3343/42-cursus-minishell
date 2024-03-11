SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra

all: $(NAME)

obj/%.o: src/%.c
	cc -c $(FLAGS) -g $< -o $@

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -g -o $(NAME)

clean:
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
