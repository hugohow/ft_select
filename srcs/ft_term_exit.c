/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:11:20 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 18:48:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_term_exit(void)
{
	ft_dprintf(0 ,"\033[?1049l");
    tcsetattr(0, TCSANOW, &(E.orig_termios));
	close(E.fd);
}