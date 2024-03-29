/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:04:33 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/28 23:08:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((char)c == '\0')
		return (char *)(s + ft_strlen(s));
	if (ft_strlen(s) == 0)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (*(s + i) == (char)c)
			return (char *)(s + i + 1);
		i--;
	}
	if (*s == (char)c)
		return (char *)s;
	return (NULL);
}
