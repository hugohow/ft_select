/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_get_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 00:54:18 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/29 00:57:15 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

int ft_term_get_pos(int *col, int *row)
{
    int ret;
    int i;
    int pow;
    char ch;
    char buf[30]={0};

    *col = 0;
    *row = 0;
    write(1, "\033[6n", 4);   
    i = 0; 
    ch = 0;
    while (ch != 'R')
    {
        ret = read(0, &ch, 1);
        if ( !ret ) {
            fprintf(stderr, "getpos: error reading response!\n");
            return (1);
        }
        buf[i] = ch;
        i++;
    }
    if (i < 2) {
        printf("i < 2\n");
        return(1);
    }

    i -= 2;
    pow = 1;
    while (buf[i] != ';')
    {
        *col = *col + ( buf[i] - '0' ) * pow;
        i--;
        pow *= 10;
    }

    i -= 1;
    pow = 1;
    while (buf[i] != '[')
    {
        *row = *row + ( buf[i] - '0' ) * pow;
        i--;
        pow *= 10;
    }
    return (0);
}