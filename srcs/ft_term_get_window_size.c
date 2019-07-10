/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_get_window_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:55:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:25:56 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

int ft_term_get_window_size(void)
{
	struct winsize ws;
	t_vars *p_vars;

	p_vars = get_vars();
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
	{
		return (-1);
	}
	p_vars->screencols = ws.ws_col;
	p_vars->screenrows = ws.ws_row;
    return (0);
}
