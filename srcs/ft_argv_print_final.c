/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_print_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:59:58 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/24 19:32:28 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_nb_selected(void)
{
	int		i;
	int		len;
	t_vars	*p_vars;

	p_vars = get_vars();
	len = 0;
	i = 0;
	while (p_vars->argv[i])
	{
		if (p_vars->argv[i]->selected == 1)
			len++;
		i++;
	}
	return (len);
}

void	ft_argv_print_final(void)
{
	int		i;
	int		len;
	t_vars	*p_vars;

	p_vars = get_vars();
	len = get_nb_selected();
	i = 0;
	while (p_vars->argv[i])
	{
		if (p_vars->argv[i]->selected == 1)
		{
			ft_putstr_fd(p_vars->argv[i]->arg, 1);
			if (len != 1)
				ft_putstr_fd(" ", 1);
			len--;
		}
		i++;
	}
}
