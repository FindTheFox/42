/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:19:59 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/09 21:25:22 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
    int     i;
    char    *s2;

    if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
        return (0);
    i = 0;
    while (s1[i])
    {
        s2[i] = (*f)(i, s1[i]);
        i++;
    }
    return (s2);
}