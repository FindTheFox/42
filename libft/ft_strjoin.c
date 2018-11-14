/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 02:28:05 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/12 03:03:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *dest;
    int     ss1;
    int     ss2;

    ss1 = ft_strlen((char *)s1);
    ss2 = ft_strlen((char *)s2);
    if (!(dest = (char *)malloc(sizeof(char) * (ss1 + ss2))))
        return (0);
    dest = ft_strcpy(dest, (char *)s1);
    dest = ft_strcat(dest, (char *)s2);
    return (dest);
}