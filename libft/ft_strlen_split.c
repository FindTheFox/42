/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 04:22:17 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/12 04:22:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int      ft_strsplit_lenword(const char *s, char c)
{
    int     len;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    return (len);
}

int     ft_strsplit_ctword(const char *s, char c)
{
    int     len;
    int     i;

    len = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] && s[i] != c)
            len++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (len);
}