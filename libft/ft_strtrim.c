/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:09:19 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 02:11:33 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(const char *s)
{
    char    *dest;
    int     len;
    int     i;

    i = -1;
    len = ft_strlen((char *)s);
    while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
        len--;
    while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
        len--;
    if (len <= 0)
        len = 0;
    if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    s += i;
    i = -1;
    while (++i < len)
        dest[i] = *s++;
    dest[i] = '\0';
    return (dest);
}