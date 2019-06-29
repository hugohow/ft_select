/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 19:36:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"


void editorRefreshScreen() {
	int i;

	i = 0;
	while (i < E.line + 1)
	{
		ft_dprintf(0 ,"\033[K");
		ft_dprintf(0 ,"\033[A");
		i++;
	}
	E.line = 0;
	ft_argv_print();
}

static void sig_handler(int signo)
{
    if (signo == SIGWINCH)
	{
		if (ft_term_get_window_size() == -1)
			return ;
		editorRefreshScreen();
	}
	if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ft_term_exit();
	}
	if (signo == SIGCONT)
	{
		signal(SIGTSTP, sig_handler);
		signal(SIGCONT, sig_handler);
		int i;

		i = 0;
		while (i < E.line)
		{
			ft_dprintf(0 ,"\n");
			i++;
		}
		ft_term_init();
	}
}


int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		exit (1);
	}
    if (signal(SIGWINCH, sig_handler) == SIG_ERR)
        ft_dprintf(2 ,"\ncan't catch SIGWINCH\n");
    if (signal(SIGCONT, sig_handler) == SIG_ERR)
        ft_dprintf(2 ,"\ncan't catch SIGCONT\n");
    if (signal(SIGTSTP, sig_handler) == SIG_ERR)
        ft_dprintf(2 ,"\ncan't catch SIGTSTP\n");
	if (!isatty(STDERR_FILENO))
	{
		ft_putendl_fd("Not a terminal.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_init_global(argc + 1, argv + 1);
	ft_term_init();
	while (42)
	{
		editorRefreshScreen();
		if (ft_term_apply_key() == 0)
			break ;
	}
	ft_argv_print_final();
	ft_term_exit();
	ft_free_global();
	return (0);
}
