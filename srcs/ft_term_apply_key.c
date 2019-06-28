/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_apply_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:52:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 01:17:37 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void exit_select()
{
	ft_dprintf(0 ,"\033[u");
	ft_term_exit(&E.orig_termios);
}


void editor_move_cursor(int key) {
	int index;

	if (key == ARROW_LEFT)
	{
		index = E.cy * E.nb_col + (E.cx - 1);
		if (index >= 0)
		{
			E.cx--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_RIGHT)
	{
		index = E.cy * E.nb_col + (E.cx + 1);
		if (index < E.argc - 2)
		{
			E.cx++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_UP)
	{
		index = (E.cy - 1) * E.nb_col + E.cx;
		if (index >= 0)
		{
			E.cy--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_DOWN)
	{
		index = (E.cy + 1) * E.nb_col + E.cx;
		if (index < E.argc - 2)
		{
			E.cy++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}

}

void delete_element_list()
{
	int i;

	i = E.index;
	while (E.argv[i + 1])
	{
		E.argv[i] = E.argv[i + 1];
		i++;
	}
	E.argc--;
	editor_move_cursor(ARROW_LEFT);
	// editorRefreshScreen(E.argc, E.argv);
}

void select_element_list()
{
	E.argv[E.index]->selected = E.argv[E.index]->selected ? 0 : 1;
	editor_move_cursor(ARROW_RIGHT);
}




void ft_term_apply_key(void) 
{
	char *ap;
	char *standstr;

	(void)ap;
	(void)standstr;
  int c = ft_term_read_key();
  switch (c) {
	case 27:
	case 10:
    case CTRL_KEY('z'):
      exit_select();
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
		editor_move_cursor(c);
		break;
    case 8:
    case 127:
		delete_element_list();
		break;
    case 32:
		select_element_list();
		break;
	}
}