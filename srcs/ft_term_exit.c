/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:11:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/27 20:00:21 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_term_exit(void)
{
	t_vars	*p_vars;

	p_vars = get_vars();
	// ft_dprintf(0, "\033[?1049l");
	ft_dprintf(0, "\e[?25h");
	tcsetattr(0, TCSANOW, &(p_vars->orig_termios));
	ft_dprintf(0, "dssds");
	// close(p_vars->fd);
}
