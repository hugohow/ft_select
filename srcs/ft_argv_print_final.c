/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:59:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:25:26 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_print_final()
{
	int i;
	t_vars *p_vars;

	p_vars = get_vars();
	i = 0;
	while (p_vars->argv[i])
	{
		if (p_vars->argv[i]->selected == 1)
		{
			ft_putstr_fd(p_vars->argv[i]->arg, 1);
			ft_putstr_fd(" ", 1);
		}
		i++;
	}
}