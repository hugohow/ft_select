NAME 		=		ft_select
CC			= 		gcc
CFLAGS 		= 		-Wall -Werror -Wextra -g -g3 -Iincludes
ifeq ($(shell uname),Darwin)
TERMFLAG 	= 		-ltermcap
else
TERMFLAG 	= 		-lcurses
endif
OBJ 		= 		$(SRC:.c=.o)

C_OK		=		"\033[35m"
C_GOOD		=		"\033[32m"
C_NO		=		"\033[00m"

SUCCESS		=		$(C_GOOD)SUCCESS$(C_NO)
OK			=		$(C_OK)OK$(C_NO)

DEBUG = #-g3 -fsanitize=address

SRC =	srcs/ft_argv_delete.c	\
		srcs/ft_argv_print.c			\
		srcs/ft_argv_print_final.c		\
		srcs/ft_argv_get_color.c		\
		srcs/ft_argv_select.c			\
		srcs/ft_cursor_move.c			\
		srcs/ft_cursor_search.c			\
		srcs/ft_global.c				\
		srcs/ft_term_apply_key.c		\
		srcs/ft_term_exit.c				\
		srcs/ft_term_get_window_size.c	\
		srcs/ft_term_init.c				\
		srcs/ft_term_read_key.c			\
		srcs/ft_signal_handler.c		\
		srcs/ft_signals.c		\
		srcs/main.c						

all: $(NAME)


%.o: %.c
	@printf "[$(NAME)] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[$(NAME)] Compiling [:.]\r"

$(NAME): $(OBJ)
	@make -C libft/
	@echo "Creating" [ $(NAME) ]
	@$(CC) $(CFLAGS) $(INCLUDES) $^ libft/libft.a -o $(NAME) $(TERMFLAG)
	@echo "Creation" [ $(NAME) ] $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[$(NAME)] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)
	
re: fclean all

test: re
	./$(NAME) 123456789 23456789 3456789 456789 56789 6789 789 89 9

.PHONY: all clean fclean re test