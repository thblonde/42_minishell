NAME = minishell
CFLAGS = -Wall -Wextra -Werror
OBJECTS = src/main.o 
RLINE = -lreadline

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	cc $(CFLAGS) $(OBJECTS) -o $@ libft/libft.a $(RLINE)

main.o: include/minishell.h
	cc -c src/main.c

clean:
	rm -rf $(OBJECTS)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	
re: fclean all
