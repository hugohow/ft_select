/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 02:07:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"


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
	argc++;
	argv++;
	ft_term_init(&E.orig_termios, &new_termios, argc, argv);
	while (42)
	{
		editorRefreshScreen(E.argc, E.argv);
		ft_term_apply_key();
	}
	return (0);
}
