/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:27:31 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/12 01:58:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strequ(const char *s1, const char *s2)
{
    int i;

    i = 0;
    if ((!s1[i] && s2[i]) || (!s2[i] && s1[i]))
        return (0);
    while (s1[i] && s2[i])
    {
        if (ft_strcmp(&(s1[i]), &(s2[i])) == 0)
            i++;
        else
            return (0);
    }
    return (1);
}