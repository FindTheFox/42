/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:58:28 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 02:11:33 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_strsplit(const char *s, char c)
{
    char    **dest;
    int     i;
    int     j;
    int     k;

    if (!(dest = (char **)malloc(sizeof(char *) * (ft_strsplit_ctword(s, c) + 1))))
        return (0);
    i = 0;
    j = 0;
    while (s[i])
    {
        k = 0;
        while (s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            if (!(dest[j] = (char *)malloc(sizeof(char) * (ft_strsplit_lenword(&s[i], c) + 1))))
                return (0);
            while (s[i] && s[i] != c)
                dest[j][k++] = s[i++];
            dest[j++][k] = '\0';
        }
    }
    dest[j] = NULL;
    return (dest);
}