/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:18:48 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 01:44:11 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_print(int argc, t_arg **list_t_arg)
{
	int i;

	if (argc > E.screencols/20)
		E.nb_col = E.screencols/40;
	else
		E.nb_col = E.screencols/20;
	E.nb_row = (argc - 1)/E.nb_col;
	E.cy = E.index / E.nb_col;
	E.cx = E.index % E.nb_col;
	
	
	i = 0;
	while (i < argc - 2)
	{
		if (i % E.nb_col == 0)
		{
			ft_dprintf(0 ,"\r\n");
			E.line++;
		}
		if (list_t_arg[i]->selected == 1)
		{
			ft_putstr_fd("\x1b[45m", 0);
		}
		if (i == E.index)
		{
			ft_putstr_fd("\e[4m", 0);
		}
		ft_dprintf(0 ,"%-20s\x1b[0m", list_t_arg[i]->arg);
		i++;
	}
	ft_dprintf(0 ,"\r\n");
}