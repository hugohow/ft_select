/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:57:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 02:06:16 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void initEditor(int argc, char **argv) {
	t_arg **list_t_arg;
	t_arg *arg;
	int i;
	int k;

	i = 0;
	k = 0;
	list_t_arg = malloc(argc * sizeof(t_arg *));
	while (argv[i])
	{
		arg = malloc(sizeof(t_arg));
		arg->arg = argv[i];
		arg->selected = 0;
		list_t_arg[k] = arg;
		k++;
		i++;
	}
	E.cx = 0;
	E.cy = 0;
	E.index = 0;
	E.argv = list_t_arg;
	E.argc = argc;
	E.line = 0;
	if (ft_term_get_window_size(&E.screenrows, &E.screencols) == -1)
	{
		return ;
	}
}


int ft_term_init(struct termios *orig_termios, struct termios *new_termios, int argc, char **argv)
{
    char *term_name;
    int ret;

    if ((term_name = getenv("TERM")))
		ret = tgetent(NULL, term_name);
	else
		ret = tgetent(NULL, "xterm-256color");
    if (ret == -1)
    {
        printf("Could not access to the termcap database..\n");
        return (-1);
    }
    else if (ret == 0)
    {
        printf("Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_name);
        return (-1);
    }
	tcgetattr(STDIN_FILENO, orig_termios);
	*new_termios = *orig_termios;
    new_termios->c_lflag &= ~(ICANON | ECHO);
	new_termios->c_lflag |= ISIG;
    new_termios->c_cc[VMIN] = 1;
	new_termios->c_cc[VTIME] = 1;
  	tcsetattr(0, TCSAFLUSH, new_termios);
	initEditor(argc, argv);
    return (0);
}