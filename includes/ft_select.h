/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:07:10 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:31:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <sys/ioctl.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_select_struc.h"
# define ARROW_LEFT 1000
# define ARROW_RIGHT 1001
# define ARROW_UP 1002
# define ARROW_DOWN 1003
# define CTRL_L ('l' & 0x1f)
# define CTRL_K ('k' & 0x1f)
# define CTRL_H ('h' & 0x1f)
# define CTRL_N ('n' & 0x1f)
# define CTRL_Z ('z' & 0x1f)
# define ANSI_COLOR_FG_BLACK "\x1b[30m"
# define ANSI_COLOR_FG_RED "\x1b[31m"
# define ANSI_COLOR_FG_GREEN "\x1b[32m"
# define ANSI_COLOR_FG_BROWN "\x1b[33m"
# define ANSI_COLOR_FG_BLUE "\x1b[34m"
# define ANSI_COLOR_FG_MAGENTA "\x1b[35m"
# define ANSI_COLOR_FG_CYAN "\x1b[36m"
# define ANSI_COLOR_FG_WITHE "\x1b[37m"
# define ANSI_COLOR_FG_BOLD_BLACK "\x1b[90m"
# define ANSI_COLOR_FG_BOLD_RED "\x1b[91m"
# define ANSI_COLOR_FG_BOLD_GREEN "\x1b[92m"
# define ANSI_COLOR_FG_BOLD_BROWN "\x1b[93m"
# define ANSI_COLOR_FG_BOLD_BLUE "\x1b[94m"
# define ANSI_COLOR_FG_BOLD_MAGENTA "\x1b[95m"
# define ANSI_COLOR_FG_BOLD_CYAN "\x1b[96m"
# define ANSI_COLOR_FG_BOLD_GREY "\x1b[97m"
# define ANSI_COLOR_BG_BLACK "\x1b[40m"
# define ANSI_COLOR_BG_RED "\x1b[41m"
# define ANSI_COLOR_BG_GREEN "\x1b[42m"
# define ANSI_COLOR_BG_BROWN "\x1b[43m"
# define ANSI_COLOR_BG_BLUE "\x1b[44m"
# define ANSI_COLOR_BG_MAGENTA "\x1b[45m"
# define ANSI_COLOR_BG_CYAN "\x1b[46m"
# define ANSI_COLOR_BG_WITHE "\x1b[47m"
# define ANSI_COLOR_BG_BOLD_BLACK "\x1b[100m"
# define ANSI_COLOR_BG_BOLD_RED "\x1b[101m"
# define ANSI_COLOR_BG_BOLD_GREEN "\x1b[102m"
# define ANSI_COLOR_BG_BOLD_BROWN "\x1b[103m"
# define ANSI_COLOR_BG_BOLD_BLUE "\x1b[104m"
# define ANSI_COLOR_BG_BOLD_MAGENTA "\x1b[105m"
# define ANSI_COLOR_BG_BOLD_CYAN "\x1b[106m"
# define ANSI_COLOR_BG_BOLD_GREY "\x1b[107m"
# define ANSI_COLOR_RESET "\x1b[0m"
# define SELECTED_COLOR "\x1b[7m"
# define SELECTION_COLOR "\x1b[4m"

void	ft_init_global(int argc, char **argv);
void	ft_free_global(void);
int		ft_term_init(void);
void	ft_term_exit(void);
int		ft_term_read_key(void);
int		ft_term_apply_key(void);
int		ft_term_get_window_size(void);
void	ft_argv_delete(void);
void	ft_argv_print(void);
void	ft_argv_select(void);
void	ft_argv_print_final(void);
void	ft_cursor_move(int key);
void	ft_cursor_search(int key);
void	signal_handler(int signal);
void	ft_refresh_screen(void);
char	*ft_argv_get_color(struct stat file_stat, char *buff);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
t_vars	*get_vars(void);
#endif
