/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:22:36 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/10 21:36:09 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static const t_color	g_tab_colors_fg[] =
{
	{'a', ANSI_COLOR_FG_BLACK},
	{'b', ANSI_COLOR_FG_RED},
	{'c', ANSI_COLOR_FG_GREEN},
	{'d', ANSI_COLOR_FG_BROWN},
	{'e', ANSI_COLOR_FG_BLUE},
	{'f', ANSI_COLOR_FG_MAGENTA},
	{'g', ANSI_COLOR_FG_CYAN},
	{'h', ANSI_COLOR_FG_WITHE},
	{'A', ANSI_COLOR_FG_BOLD_BLACK},
	{'B', ANSI_COLOR_FG_BOLD_RED},
	{'C', ANSI_COLOR_FG_BOLD_GREEN},
	{'D', ANSI_COLOR_FG_BOLD_BROWN},
	{'E', ANSI_COLOR_FG_BOLD_BLUE},
	{'F', ANSI_COLOR_FG_BOLD_MAGENTA},
	{'G', ANSI_COLOR_FG_BOLD_CYAN},
	{'H', ANSI_COLOR_FG_BOLD_GREY},
	{'x', ""},
	{0, ""},
};

static int				get_index(struct stat file_stat)
{
	if (S_ISLNK(file_stat.st_mode))
		return (2);
	else if (S_ISSOCK(file_stat.st_mode))
		return (4);
	else if (S_ISFIFO(file_stat.st_mode))
		return (6);
	else if (S_ISBLK(file_stat.st_mode))
		return (10);
	else if (S_ISCHR(file_stat.st_mode))
		return (12);
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH)\
		&& (file_stat.st_mode & S_ISVTX))
		return (18);
	else if (S_ISDIR(file_stat.st_mode) && (file_stat.st_mode & S_IWOTH))
		return (20);
	else if (S_ISDIR(file_stat.st_mode))
		return (0);
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISUID))
		return (14);
	else if ((file_stat.st_mode & S_IXUSR) && (file_stat.st_mode & S_ISGID))
		return (16);
	else if (file_stat.st_mode & S_IXUSR)
		return (8);
	else
		return (-1);
}

static char				*get_fg(char color, char *fg)
{
	int		k;

	k = 0;
	fg[0] = 0;
	while (g_tab_colors_fg[k].key)
	{
		if (g_tab_colors_fg[k].key == color)
		{
			ft_strcpy(fg, g_tab_colors_fg[k].str);
			break ;
		}
		k++;
	}
	return (fg);
}


char *ft_argv_get_color(struct stat file_stat, char *buff)
{
	char	*colors;
	int		i;
	char	fg[10];

	colors = ft_strdup(getenv("LSCOLORS"));
	if (colors == NULL)
		colors = ft_strdup("Gxfxcxdxbxegedabagacad");
	i = get_index(file_stat);
	if (ft_strlen(colors) < 22)
	{
		ft_memdel((void **)&colors);
		return (buff);
	}
	if (i == -1)
	{
		ft_memdel((void **)&colors);
		return (buff);
	}
	get_fg(colors[i], fg);
	ft_strcat(buff, fg);
	ft_memdel((void **)&colors);
	return (buff);
}