/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:01:49 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 18:26:47 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"



void ft_init_global(int argc, char **argv)
{
	int i;
	struct stat	file_stat;


	i = 0;
	E.argv = (t_arg **)ft_memalloc(argc * sizeof(t_arg *));
	while (argv[i])
	{
		ft_memset((void*)&file_stat, 0, sizeof(file_stat));
		(E.argv)[i] = (t_arg *)ft_memalloc(sizeof(t_arg));
		((E.argv)[i])->arg = argv[i];
		((E.argv)[i])->selected = 0;
		if (stat(argv[i], &file_stat) < 0)
			{
				
			}
		else
		{
			ft_argv_get_color(file_stat, ((E.argv)[i])->colors);
		}
		i++;
	}
	E.cx = 0;
	E.cy = 0;
	E.index = 0;
	E.argc = argc;
	E.line = 0;
	E.fd = 0;
	if (ft_term_get_window_size() == -1)
	{
		return ;
	}
}

void ft_free_global()
{
	int i;
	t_arg *arg;

	i = 0;
	while (E.argv[i])
	{
		arg = E.argv[i];
		if (arg)
			ft_memdel((void **)&(arg));
		i++;
	}
	ft_memdel((void **)&(E.argv));
}