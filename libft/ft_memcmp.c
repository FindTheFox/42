/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:51:56 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/07 17:59:40 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n)
		i++;
    if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
        return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
    return (0);
}
