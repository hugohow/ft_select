/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:18:48 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:25:33 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int ft_argv_print_init()
{
	int max_len;
	t_vars *p_vars;

	p_vars = get_vars();
	max_len = 30;
	p_vars->nb_col = p_vars->screencols/max_len;
	if (p_vars->nb_col == 0)
	{
		ft_dprintf(p_vars->fd ,"\nResize it !\n");
		p_vars->line = 1;
		return (-1);
	}
	p_vars->nb_row = (p_vars->argc - 2) / p_vars->nb_col;
	if (p_vars->nb_row + 1 > p_vars->screenrows)
	{
		ft_dprintf(p_vars->fd ,"\nResize it !\n");
		p_vars->line = 1;
		return (-1);
	}
	p_vars->nb_row = (p_vars->argc - 1)/p_vars->nb_col;
	p_vars->cy = p_vars->index / p_vars->nb_col;
	p_vars->cx = p_vars->index % p_vars->nb_col;
	ft_dprintf(p_vars->fd ,"\033[2J\x1b[H");
	ft_dprintf(p_vars->fd  ,"\rFT_SELECT 👇\n");
	return (0);
}

void ft_argv_print(void)
{
	int i;
	int max_len;
	t_vars *p_vars;

	p_vars = get_vars();
	max_len = 30;
	i = 0;
	if (ft_argv_print_init() < 0)
		return ;
	while (i < p_vars->argc - 2)
	{
		if (i % p_vars->nb_col == 0)
		{
			ft_dprintf(p_vars->fd ,"\r\n");
			p_vars->line++;
		}
		if ((p_vars->argv)[i]->selected == 1)
			ft_putstr_fd(SELECTED_COLOR, p_vars->fd);
		if (i == p_vars->index)
			ft_putstr_fd(SELECTION_COLOR, p_vars->fd);
		ft_putstr_fd((p_vars->argv)[i]->colors, p_vars->fd);
		ft_dprintf(p_vars->fd ,"%-*.*s\x1b[0m", max_len, max_len, (p_vars->argv)[i]->arg);
		i++;
	}
	ft_dprintf(p_vars->fd ,"\r\n");
}