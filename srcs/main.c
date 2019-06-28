/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 01:34:34 by hhow-cho         ###   ########.fr       */
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


void editorRefreshScreen(int argc, t_arg **list_t_arg) {
	
	
	ft_argv_clear();


	E.line = 0;
	ft_argv_print(argc, list_t_arg);
}




static void sig_handler(int signo)
{
    if (signo == SIGWINCH)
	{
		if (ft_term_get_window_size(&E.screenrows, &E.screencols) == -1)
			return ;
		editorRefreshScreen(E.argc, E.argv);
	}
}


int main(int argc, char **argv)
{
	int i;	
	struct termios orig_termios;
	struct termios new_termios;

	i = 1;
	(void)(orig_termios);
	if (argc < 2)
		return (0);
    if (signal(SIGWINCH, sig_handler) == SIG_ERR)
        ft_dprintf(0 ,"\ncan't catch SIGWINCH\n");
	ft_term_init(&E.orig_termios, &new_termios);
	argc++;
	argv++;
	initEditor(argc, argv);
	while (42)
	{
		editorRefreshScreen(E.argc, E.argv);
		ft_term_apply_key();
	}
	return (0);
}
