/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:11:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 19:56:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_term_exit(void)
{
	t_vars	*p_vars;

	p_vars = get_vars();
	ft_dprintf(0, "\033[?1049l");
	tcsetattr(0, TCSANOW, &(p_vars->orig_termios));
	close(p_vars->fd);
}
