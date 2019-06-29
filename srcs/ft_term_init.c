/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:57:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 23:17:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_getttyfd(void)
{
	char	*tty;

	tty = ttyname(0);
	E.fd = open(tty, O_WRONLY);
	ft_memdel((void **)&tty);
}

int ft_term_init(void)
{
    char *term_name;
    int ret;

    if ((term_name = getenv("TERM")))
		ret = tgetent(NULL, term_name);
	else
		ret = tgetent(NULL, "xterm-256color");
    if (ret == -1)
    {
        ft_dprintf(2, "Could not access to the termcap database..\n");
        return (-1);
    }
    else if (ret == 0)
    {
        ft_dprintf(2, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_name);
        return (-1);
    }
	tcgetattr(STDIN_FILENO, &(E.orig_termios));
	E.new_termios = E.orig_termios;
    (E.new_termios).c_lflag &= ~(ICANON | ECHO);
    (E.new_termios).c_cc[VMIN] = 1;
	(E.new_termios).c_cc[VTIME] = 1;
  	tcsetattr(0, TCSANOW, &(E.new_termios));
	ft_dprintf(0 ,"\033[?1049h\033[H");
	ft_getttyfd();
    return (0);
}