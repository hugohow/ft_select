/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:01:15 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/13 20:25:01 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 == NULL)
		return (NULL);
	if (!(copy = (char *)ft_memalloc(\
		(ft_strlen((char *)s1) + 1) * sizeof(char))))
		return (NULL);
	copy = ft_strcpy(copy, s1);
	return (copy);
}
