/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_apply_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:52:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/14 19:26:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_term_apply_key(void)
{
	int	c;

	c = ft_term_read_key();
	if (c == ESC_KEY)
	{
		signals_disable();
		ft_term_exit();
		ft_free_global();
		exit(0);
	}
	if (c == SPC_KEY)
		ft_argv_select();
	if (c == BSP_KEY || c == DEL_KEY)
		ft_argv_delete();
	if (c == LEFT_KEY || c == UP_KEY || c == RIGHT_KEY || c == DOWN_KEY)
		ft_cursor_move(c);
	if (c == ENTER_KEY)
		return (0);
	if (ft_isalnum(c))
		ft_cursor_search(c);
	return (1);
}
