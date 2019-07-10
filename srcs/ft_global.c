/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:01:49 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:56:56 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void ft_init_vars(int argc)
{
	t_vars *p_vars;

	p_vars = get_vars();
	if (ft_term_get_window_size() == -1)
	{
		ft_free_global();
		exit (1);
	}
	p_vars->cx = 0;
	p_vars->cy = 0;
	p_vars->index = 0;
	p_vars->argc = argc;
	p_vars->line = 0;
	p_vars->fd = 0;
}

void ft_init_global(int argc, char **argv)
{
	int i;
	struct stat	file_stat;
	t_vars *p_vars;

	p_vars = get_vars();
	i = 0;
	if (!(p_vars->argv = (t_arg **)ft_memalloc(argc * sizeof(t_arg *))))
	{
		ft_free_global();
		exit (1);
	}
	while (argv[i])
	{
		ft_memset((void*)&file_stat, 0, sizeof(file_stat));
		if (!((p_vars->argv)[i] = (t_arg *)ft_memalloc(sizeof(t_arg))))
		{
			ft_free_global();
			exit (1);
		}
		((p_vars->argv)[i])->arg = argv[i];
		((p_vars->argv)[i])->selected = 0;
		if (lstat(argv[i], &file_stat) >= 0)
			ft_argv_get_color(file_stat, ((p_vars->argv)[i])->colors);
		i++;
	}
	ft_init_vars(argc);
}

void ft_free_global()
{
	int i;
	t_arg *arg;
	t_vars *p_vars;

	p_vars = get_vars();
	i = 0;
	while (p_vars->argv[i])
	{
		arg = p_vars->argv[i];
		if (arg)
			ft_memdel((void **)&(arg));
		i++;
	}
	ft_memdel((void **)&(p_vars->argv));
}