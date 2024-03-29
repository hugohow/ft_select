/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:57:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/27 19:53:54 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_getttyfd(void)
{
	char	*tty;
	t_vars	*p_vars;

	p_vars = get_vars();
	tty = ttyname(0);
	printf("tty : %s", tty);
	p_vars->fd = open(tty, O_WRONLY);
	if (p_vars->fd < 0)
	{
		ft_free_global();
		exit(1);
	}
}

static void	ft_init_termios(void)
{
	t_vars	*p_vars;

	p_vars = get_vars();
	tcgetattr(STDIN_FILENO, &(p_vars->orig_termios));
	p_vars->new_termios = p_vars->orig_termios;
	(p_vars->new_termios).c_lflag &= ~(ICANON);
	(p_vars->new_termios).c_lflag &= ~(ECHO);
	(p_vars->new_termios).c_cc[VMIN] = 1;
	(p_vars->new_termios).c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &(p_vars->new_termios));
}

static int	handle_error_2(void)
{
	if (!isatty(STDIN_FILENO))
	{
		ft_putstr_fd("Not a terminal.\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

static int	handle_error(void)
{
	char	*term_name;
	int		ret;

	if ((term_name = getenv("TERM")))
		ret = tgetent(NULL, term_name);
	else
	{
		ft_putstr_fd("Could not find the terminal name.\n", STDERR_FILENO);
		return (-1);
	}
	if (handle_error_2() < 0)
		return (-1);
	if (ret == -1)
	{
		ft_dprintf(2, "Could not access to the termcap database..\n");
		return (-1);
	}
	else if (ret == 0)
	{
		ft_dprintf(2, "Terminal type '%s' is not defined.\n", term_name);
		return (-1);
	}
	return (0);
}

int			ft_term_init(void)
{
	if (handle_error() < 0)
		return (-1);
	ft_init_termios();
	ft_dprintf(0, "\033[?1049h\033[H");
	ft_dprintf(0, "\e[?25l");
	ft_getttyfd();
	return (0);
}
