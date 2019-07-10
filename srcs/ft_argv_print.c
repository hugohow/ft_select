/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:18:48 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 18:27:20 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_print(void)
{
	int i;

	int max_len;

	max_len = 30;
	E.nb_col = E.screencols/max_len;
	if (E.nb_col == 0)
	{
		ft_dprintf(E.fd ,"\nResize it !\n");
		E.line = 1;
		return ;
	}

	E.nb_row = (E.argc - 2) / E.nb_col;
	if (E.nb_row + 1 > E.screenrows)
	{
		ft_dprintf(E.fd ,"\nResize it !\n");
		E.line = 1;
		return ;
	}

	E.nb_row = (E.argc - 1)/E.nb_col;
	E.cy = E.index / E.nb_col;
	E.cx = E.index % E.nb_col;
	
	ft_dprintf(E.fd ,"\033[2J\x1b[H");
	i = 0;
	while (i < E.argc - 2)
	{
		if (i % E.nb_col == 0)
		{
			ft_dprintf(E.fd ,"\r\n");
			E.line++;
		}
		if ((E.argv)[i]->selected == 1)
		{
			ft_putstr_fd(SELECTED_COLOR, E.fd);
		}
		if (i == E.index)
		{
			ft_putstr_fd(SELECTION_COLOR, E.fd);
		}
		ft_putstr_fd((E.argv)[i]->colors, E.fd);
		ft_dprintf(E.fd ,"%-*.*s\x1b[0m", max_len, max_len, (E.argv)[i]->arg);
		i++;
	}
	ft_dprintf(E.fd ,"\r\n");
}