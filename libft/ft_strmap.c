/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:12:09 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/09 21:18:58 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmap(const char *s1, char (*f)(char))
{
    int     i;
    char    *s2;

    if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
        return (0);
    i = 0;
    while (s1[i])
    {
        s2[i] = (*f)(s1[i]);
        i++; 
    }
    return (s2);
}