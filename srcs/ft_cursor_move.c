/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:02:55 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:27:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_cursor_move_left(void)
{
	int		index;
	t_vars	*p_vars;

	p_vars = get_vars();
	index = p_vars->cy * p_vars->nb_col + (p_vars->cx - 1);
	if (index >= 0)
	{
		p_vars->cx--;
		p_vars->index = p_vars->cy * p_vars->nb_col + p_vars->cx;
	}
}

static void	ft_cursor_move_right(void)
{
	int		index;
	t_vars	*p_vars;

	p_vars = get_vars();
	index = p_vars->cy * p_vars->nb_col + (p_vars->cx + 1);
	if (index < p_vars->argc - 2)
	{
		p_vars->cx++;
		p_vars->index = p_vars->cy * p_vars->nb_col + p_vars->cx;
	}
	else
	{
		p_vars->cx = 0;
		p_vars->cy = 0;
		p_vars->index = 0;
	}
}

static void	ft_cursor_move_up(void)
{
	int		index;
	t_vars	*p_vars;

	p_vars = get_vars();
	index = (p_vars->cy - 1) * p_vars->nb_col + p_vars->cx;
	if (index >= 0)
	{
		p_vars->cy--;
		p_vars->index = p_vars->cy * p_vars->nb_col + p_vars->cx;
	}
}

static void	ft_cursor_move_down(void)
{
	int		index;
	t_vars	*p_vars;

	p_vars = get_vars();
	index = (p_vars->cy + 1) * p_vars->nb_col + p_vars->cx;
	if (index < p_vars->argc - 2)
	{
		p_vars->cy++;
		p_vars->index = p_vars->cy * p_vars->nb_col + p_vars->cx;
	}
}

void		ft_cursor_move(int key)
{
	if (key == ARROW_LEFT)
		ft_cursor_move_left();
	if (key == ARROW_RIGHT)
		ft_cursor_move_right();
	if (key == ARROW_UP)
		ft_cursor_move_up();
	if (key == ARROW_DOWN)
		ft_cursor_move_down();
}
