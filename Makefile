NAME = minishell
CFLAGS = -Wall -Wextra -Werror
OBJECTS = src/main.o src/init.o src/token.o
RLINE = -lreadline

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	cc $(CFLAGS) $(OBJECTS) -o $@ libft/libft.a $(RLINE)

main.o: include/minishell.h
	cc -c src/main.c

init.o: include/minishell.h
	cc -c src/init.c

token.o: include/minishell.h
	cc -c src/token.o

clean:
	rm -rf $(OBJECTS)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	
re: fclean all
