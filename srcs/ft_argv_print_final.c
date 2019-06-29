/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:59:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 19:00:09 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_print_final()
{
	int i;

	i = 0;
	while (i < E.line)
	{
		ft_dprintf(0,"\033[K");
		ft_dprintf(0,"\033[A");
		i++;
	}
	i = 0;
	ft_dprintf(0 ,"\033[K");
	while (E.argv[i])
	{
		if (E.argv[i]->selected == 1)
		{
			ft_putstr_fd(E.argv[i]->arg, 1);
			ft_putstr_fd(" ", 1);
		}
		i++;
	}
}