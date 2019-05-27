/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 02:46:59 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/25 02:49:24 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double      ft_lerp(double first, double second, int p)
{
    if (first == second)
        return (first);
    return (first + (second - first) * p);
}