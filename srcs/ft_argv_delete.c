/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:02:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 18:58:27 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_delete(void)
{
	int i;

	i = E.index;
	while (E.argv[i + 1])
	{
		E.argv[i] = E.argv[i + 1];
		i++;
	}
	E.argc--;
	ft_cursor_move(ARROW_LEFT);
}
