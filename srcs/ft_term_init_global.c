/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init_global.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:01:49 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 19:02:02 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_getttyfd(void)
{
	int		fd;
	char	*tty;

	tty = ttyname(0);
	fd = open(tty, O_WRONLY);
	return (fd);
}


void ft_term_init_global(int argc, char **argv)
{
	t_arg **list_t_arg;
	t_arg *arg;
	int i;
	int k;

	i = 0;
	k = 0;
	list_t_arg = ft_memalloc(argc * sizeof(t_arg *));
	while (argv[i])
	{
		arg = ft_memalloc(sizeof(t_arg));
		arg->arg = argv[i];
		arg->selected = 0;
		list_t_arg[k] = arg;
		k++;
		i++;
	}
	E.cx = 0;
	E.cy = 0;
	E.index = 0;
	E.argv = list_t_arg;
	E.argc = argc;
	E.line = 0;
	E.fd = ft_getttyfd();
	if (ft_term_get_window_size() == -1)
	{
		return ;
	}
}