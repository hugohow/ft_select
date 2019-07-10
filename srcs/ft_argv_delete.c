/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:02:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 18:38:11 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_delete(void)
{
	int i;

	i = E.index;
	ft_memdel((void **)&(E.argv[i]));
	while (E.argv[i + 1])
	{
		E.argv[i] = E.argv[i + 1];
		i++;
	}
	E.argv[i] = 0;
	E.argc--;
	if (E.argc == 2)
	{
		ft_term_exit();	
		ft_free_global();
		exit (0);
	}
	ft_cursor_move(ARROW_LEFT);
}

