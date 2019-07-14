/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:30:35 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/14 21:38:49 by hhow-cho         ###   ########.fr       */
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
	ft_term_exit();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	sigcont_handler(void)
{
	ft_term_init();
	if (ft_term_get_window_size() == -1)
		return ;
	ft_refresh_screen();
	signals_enable();
}

void		signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGABRT || signal == SIGSTOP || \
		signal == SIGKILL || signal == SIGQUIT)
		sigint_handler();
	else if (signal == SIGWINCH)
		sigwinch_handler();
	else if (signal == SIGTSTP)
		sigtstp_handler();
	else if (signal == SIGCONT)
		sigcont_handler();
}
