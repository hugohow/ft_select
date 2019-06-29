/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:02:55 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 02:03:05 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_cursor_move(int key)
{
	int index;

	if (key == ARROW_LEFT)
	{
		index = E.cy * E.nb_col + (E.cx - 1);
		if (index >= 0)
		{
			E.cx--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_RIGHT)
	{
		index = E.cy * E.nb_col + (E.cx + 1);
		if (index < E.argc - 2)
		{
			E.cx++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_UP)
	{
		index = (E.cy - 1) * E.nb_col + E.cx;
		if (index >= 0)
		{
			E.cy--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_DOWN)
	{
		index = (E.cy + 1) * E.nb_col + E.cx;
		if (index < E.argc - 2)
		{
			E.cy++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}

}