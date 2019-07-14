/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:02:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/14 19:23:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_argv_delete(void)
{
	int		i;
	t_vars	*p_vars;

	p_vars = get_vars();
	i = p_vars->index;
	ft_memdel((void **)&(p_vars->argv[i]));
	while (p_vars->argv[i + 1])
	{
		p_vars->argv[i] = p_vars->argv[i + 1];
		i++;
	}
	p_vars->argv[i] = 0;
	p_vars->argc--;
	if (p_vars->argc == 2)
	{
		ft_term_exit();
		ft_free_global();
		exit(0);
	}
	ft_cursor_move(LEFT_KEY);
}
