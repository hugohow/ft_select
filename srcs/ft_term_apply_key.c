/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_apply_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:52:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 19:57:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_term_apply_key(void)
{
	int	c;

	c = ft_term_read_key();
	if (c == 32)
		ft_argv_select();
	if (c == 8 || c == 127)
		ft_argv_delete();
	if (c == ARROW_UP || c == ARROW_DOWN || c == ARROW_LEFT || c == ARROW_RIGHT)
		ft_cursor_move(c);
	if (c == 10)
		return (0);
	if (c == 27)
	{
		ft_term_exit();
		ft_free_global();
		exit(0);
	}
	if (ft_isalnum(c))
		ft_cursor_search(c);
	return (1);
}
