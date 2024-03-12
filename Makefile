SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra
LIBS=-lreadline -lhistory

all: $(NAME)

obj/%.o: src/%.c
	cc -c $(FLAGS) $(LIBS) -g $< -o $@

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBS) -g -o $(NAME) 

clean:
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
