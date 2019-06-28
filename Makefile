NAME=ft_select

all:
	make -C libft/
	gcc -Wall -Werror -Wextra -g -Iincludes -lncurses *.c libft/libft.a -o $(NAME)
	./$(NAME) 123456789 23456789 3456789 456789 56789 6789 789 89 9

clean:
	make clean -C libft/
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all