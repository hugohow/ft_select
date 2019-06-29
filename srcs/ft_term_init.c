/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:57:41 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 19:34:43 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_getttyfd(void)
{
	char	*tty;

	tty = ttyname(0);
	E.fd = open(tty, O_WRONLY);
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
        printf("Could not access to the termcap database..\n");
        return (-1);
    }
    else if (ret == 0)
    {
        printf("Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_name);
        return (-1);
    }
	tcgetattr(STDIN_FILENO, &(E.orig_termios));
	E.new_termios = E.orig_termios;
    (E.new_termios).c_lflag &= ~(ICANON | ECHO);
	(E.new_termios).c_lflag |= ISIG;
    (E.new_termios).c_cc[VMIN] = 1;
	(E.new_termios).c_cc[VTIME] = 1;
  	tcsetattr(0, TCSAFLUSH, &(E.new_termios));
	ft_getttyfd();
    return (0);
}