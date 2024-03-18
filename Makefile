SRC=$(wildcard src/*/*.c)
OBJ=$(patsubst src/%.c,obj/%.o,$(SRC))
NAME=minishell
FLAGS=-Wall -Werror -Wextra
LIBS=-I./libft -L./libft -lreadline -lhistory

all:
	make -C libft
	make $(NAME)

obj/%.o: src/%.c
	cc -c $(FLAGS) $(LIBS) -g $< -o $@

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) $(LIBS) -g -o $(NAME) 

clean:
	make clean -C libft
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
