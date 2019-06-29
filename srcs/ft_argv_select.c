/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:01:44 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 02:01:51 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_argv_select()
{
	E.argv[E.index]->selected = E.argv[E.index]->selected ? 0 : 1;
	ft_cursor_move(ARROW_RIGHT);
}