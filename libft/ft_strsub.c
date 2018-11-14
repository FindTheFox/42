/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 01:59:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/12 02:26:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strsub(const char *s1, unsigned int start, size_t len)
{
    size_t  i;
    char    *dest;

    if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (i < len)
        dest[i++] = s1[start++];
    return (dest);
}