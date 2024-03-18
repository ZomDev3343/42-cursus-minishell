SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra
LIBS=-lreadline

all: $(NAME)

obj/%.o: src/%.c
	cc $(FLAGS) -c -g -o $@ $<

$(NAME): $(OBJ)
	cc $(FLAGS) $(LIBS) $(OBJ) -g -o $(NAME)

clean:
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
