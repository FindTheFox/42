/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:45:01 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/12 07:32:30 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    itoa_is_neg(int *nb, int *neg)
{
    if (*nb < 0)
    {
        *nb *= -1;
        *neg = 1;
    }
}

char    *ft_itoa(int nb)
{
    int     i;
    int     len;
    int     neg;
    char    *dest;

    neg = 0;
    itoa_is_neg(&nb, &neg);
    if (nb == -2147483648)
        return (ft_strdup("-2147483648"));
    i = nb;
    len = 2;
    while (i /= 10)
        len++;
    len += neg;
    if (!(dest = (char *)malloc(sizeof(char) * len)))
        return (0);
    if (neg)
        dest[0] = '-';
    dest[--len] = '\0';
    while (len--)
    {
        dest[len] = nb % 10 + '0';
        nb /= 10;
    }
    if (neg)
        dest[0] = '-';
    return (dest);
}