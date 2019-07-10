/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:51:39 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:25:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_cursor_search(int key)
{
	int i;
	t_vars *p_vars;

	p_vars = get_vars();
	i = 0;
	while (p_vars->argv[i])
	{
		if (p_vars->argv[i]->arg && (p_vars->argv[i]->arg)[0] && (p_vars->argv[i]->arg)[0] == key)
		{
			p_vars->index = i;
			return ;
		}
		i++;
	}
	p_vars->index = 0;
}