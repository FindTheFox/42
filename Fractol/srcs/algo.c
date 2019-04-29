/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/29 05:15:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     mandelbrot(t_fractol f, t_env *e)
{
    f.iter = 0; 
    while((f.z_r * f.z_r + f.z_i * f.z_i) < 4 && f.iter < e->max_iter)
    {
        f.tmp = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
        f.z_i = 2 * f.z_i * f.z_r + f.c_i;
        f.z_r = f.tmp;
        f.iter++; 
    }
    return (f.iter);
}

int     julia(t_fractol f, t_env *e)
{
    f.iter = 0;
    while((f.z_r * f.z_r + f.z_i * f.z_i) < 4 && f.iter < e->max_iter)
    {
        f.tmp = f.z_r * f.z_r - f.z_i + e->rng.real;
    }
}
