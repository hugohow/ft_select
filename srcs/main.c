/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:48:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:21:46 by hhow-cho         ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl_fd("usage: ./ft_select arg1 arg2 arg3 ...", 2);
		exit(EXIT_FAILURE);
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
