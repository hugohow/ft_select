/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_get_window_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:55:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 01:03:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

int ft_term_get_window_size(int *rows, int *cols)
{
  struct winsize ws;
  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
  {
	  return (-1);
  }
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return (0);
}
