/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_struc.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:03:40 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:29:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_STRUC_H
# define FT_SELECT_STRUC_H

typedef struct		s_color
{
	char			key;
	char			str[10];
}					t_color;

typedef struct		s_arg {
	char			*arg;
	int				selected;
	char			colors[10];
}					t_arg;

typedef struct		s_vars
{
	int				cx;
	int				cy;
	int				index;
	int				nb_row;
	int				nb_col;
	t_arg			**argv;
	int				argc;
	int				screenrows;
	int				screencols;
	struct termios	orig_termios;
	struct termios	new_termios;
	int				line;
	int				fd;
}					t_vars;
#endif
