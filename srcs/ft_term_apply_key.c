/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_apply_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:52:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 17:32:50 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int ft_term_apply_key(void) 
{
	char *ap;
	char *standstr;

	(void)ap;
	(void)standstr;
  int c = ft_term_read_key();
  switch (c) {
	case 10:
      return (0);
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
		ft_cursor_move(c);
		break;
    case 8:
    case 127:
		ft_argv_delete();
		break;
    case 32:
		ft_argv_select();
		break;
	}
	return (1);
}