/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_read_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:11:31 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:23:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_read_arrow(void)
{
	char	seq[3];

	if (read(STDIN_FILENO, &seq[0], 1) != 1)
		return ('\x1b');
	if (read(STDIN_FILENO, &seq[1], 1) != 1)
		return ('\x1b');
	if (seq[0] == '[')
	{
		if (seq[1] == 'A')
			return (ARROW_UP);
		if (seq[1] == 'B')
			return (ARROW_DOWN);
		if (seq[1] == 'C')
			return (ARROW_RIGHT);
		if (seq[1] == 'D')
			return (ARROW_LEFT);
	}
	return ('\x1b');
}

int	ft_term_read_key(void)
{
	int		nread;
	char	c;

	while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
	{
		if (nread == -1)
			return (0);
	}
	if (c == '\x1b')
		return (ft_read_arrow());
	else
		return (c);
}
