/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 18:48:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"


void editorRefreshScreen(void)
{
	int i;

	i = 0;
	ft_dprintf(0 ,"\033[?1049h\033[H");
	while (i < E.line + 1)
	{
		ft_dprintf(0 ,"\033[K");
		ft_dprintf(0 ,"\033[A");
		i++;
	}
	E.line = 0;
	ft_argv_print();
}


static void		signals_enable(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

static void		signals_disable(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
}



int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		exit (1);
	}
	if (!isatty(STDERR_FILENO))
	{
		ft_putendl_fd("Not a terminal.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_init_global(argc + 1, argv + 1);
	ft_term_init();
	signals_enable();
	while (42)
	{
		editorRefreshScreen();
		if (ft_term_apply_key() == 0)
			break ;
	}
	signals_disable();
	ft_term_exit();
	ft_argv_print_final();
	ft_free_global();
	return (0);
}
