/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:23:48 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 14:16:08 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef FT_SELECT_H
# define FT_SELECT_H
#include "libft.h"
#include "ft_printf.h"
#include <sys/ioctl.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <fcntl.h>

# define ARROW_LEFT 1000
# define ARROW_RIGHT 1001
# define ARROW_UP 1002
# define ARROW_DOWN 1003

#define CTRL_L ('l' & 0x1f)
#define CTRL_K ('k' & 0x1f)
#define CTRL_H ('h' & 0x1f)
#define CTRL_N ('n' & 0x1f)

# define SELECTED_COLOR "\x1b[7m"
# define SELECTION_COLOR "\x1b[41m"

typedef struct s_arg {
	char *arg;
	int selected;
}				t_arg;


struct editorConfig {
  int cx;
  int cy;
  int index;
  int nb_row;
  int nb_col;
  t_arg **argv;
  int argc;
  int 	screenrows;
  int 	screencols;
  struct termios orig_termios;
  struct termios new_termios;
  int line;
  int fd;
};
struct editorConfig E;


void ft_init_global(int argc, char **argv);
void ft_free_global(void);

int ft_term_init(void);
void ft_term_exit(void);
int    ft_term_read_key(void);
int ft_term_apply_key(void);
int ft_term_get_window_size(void);
void ft_argv_delete(void);
void ft_argv_print(void);
void ft_argv_select(void);
void ft_argv_print_final(void);

void ft_cursor_move(int key);
#endif