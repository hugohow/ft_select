/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:30:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/27 20:01:09 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sigint_handler(void)
{
	ft_term_exit();
	ft_free_global();
	exit(0);
}

static void	sigwinch_handler(void)
{
	if (ft_term_get_window_size() == -1)
		return ;
	ft_refresh_screen();
}

static void	sigtstp_handler(void)
{
	int i;

	ft_putstr_fd("term exit", 0);
	i = 0;
	while (i < 32)
	{
		if (i != SIGCONT)
			signal(i, SIG_DFL);
		i++;
	}
	ft_putstr_fd("ioctl", 0);
	ft_term_exit();
	if ((ioctl(0, TIOCSTI, "\x1A")) < 0)
	{
		ft_free_global();
		ft_dprintf(0, "toto\n");
		signals_disable();
		exit(1);
	}
	ft_putstr_fd("end", 0);
}

static void	sigcont_handler(void)
{
	if ((ft_term_init()) < 0)
	{
		ft_free_global();
		signals_disable();
		exit(1);
	}
	signals_enable();
	ft_refresh_screen();
}

void		signal_handler(int signal_id)
{
	printf("signal_id : %d", signal_id);
	if (signal_id == SIGINT || signal_id == SIGABRT || signal_id == SIGSTOP || \
		signal_id == SIGKILL || signal_id == SIGQUIT)
		sigint_handler();
	else if (signal_id == SIGWINCH)
		sigwinch_handler();
	else if (signal_id == SIGTSTP)
		sigtstp_handler();
	else if (signal_id == SIGCONT)
		sigcont_handler();
}
