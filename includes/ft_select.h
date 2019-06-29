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


#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* code source conforme à POSIX */
#define FALSE 0
#define TRUE 1
#define CTRL_KEY(k) ((k) & 0x1f)
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


void ft_term_init_global(int argc, char **argv);

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