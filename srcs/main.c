/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/25 13:21:55 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_vars			*get_vars(void)
{
	static t_vars	*p_vars;

	if (p_vars == NULL)
		p_vars = (t_vars *)ft_memalloc(sizeof(t_vars));
	return (p_vars);
}

void			ft_refresh_screen(void)
{
	int		i;
	t_vars	*p_vars;

	i = 0;
	p_vars = get_vars();
	ft_dprintf(0, "\033[?1049h\033[H");
	while (i < p_vars->line + 1)
	{
		ft_dprintf(0, "\033[K");
		ft_dprintf(0, "\033[A");
		i++;
	}
	p_vars->line = 0;
	ft_argv_print();
}

void		signals_enable(void)
{
	signal(SIGHUP, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGTRAP, signal_handler);
	signal(SIGEMT, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGBUS, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGSYS, signal_handler);
	signal(SIGPIPE, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGURG, signal_handler);
	signal(SIGCHLD, signal_handler);
	signal(SIGTTIN, signal_handler);
	signal(SIGTTOU, signal_handler);
	signal(SIGIO, signal_handler);
	signal(SIGXCPU, signal_handler);
	signal(SIGXFSZ, signal_handler);
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);
	signal(SIGINFO, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	signal(SIGINT, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

void		signals_disable(void)
{
	signal(SIGHUP, SIG_IGN);
	signal(SIGILL, SIG_IGN);
	signal(SIGTRAP, SIG_IGN);
	signal(SIGEMT, SIG_IGN);
	signal(SIGFPE, SIG_IGN);
	signal(SIGBUS, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGSYS, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGALRM, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGURG, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGIO, SIG_IGN);
	signal(SIGXCPU, SIG_IGN);
	signal(SIGXFSZ, SIG_IGN);
	signal(SIGVTALRM, SIG_IGN);
	signal(SIGPROF, SIG_IGN);
	signal(SIGINFO, SIG_IGN);
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);

	signal(SIGINT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
}

int				main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		exit(EXIT_FAILURE);
	}
	ft_init_global(argc + 1, argv + 1);
	if ((ft_term_init()) < 0)
	{
		ft_free_global();
		exit(1);
	}
	signals_enable();
	while (42)
	{
		ft_refresh_screen();
		if (ft_term_apply_key() == 0)
			break ;
	}
	signals_disable();
	ft_term_exit();
	ft_argv_print_final();
	ft_free_global();
	return (0);
}
