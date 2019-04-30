/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/30 06:39:18 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void     mandelbrot(t_fractol f, t_env *e)
{
    f.z_r = 0;
    f.z_i = 0;
    f.c_r = e->i.x / e->zoom + e->x_left;
    f.c_i = e->i.y / e->zoom + e->y_floor;
    while((f.z_r * f.z_r + f.z_i * f.z_i) < 4 && e->iter < e->max_iter)
    {
        f.tmp = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
        f.z_i = 2 * f.z_i * f.z_r + f.c_i;
        f.z_r = f.tmp;
        e->iter++;
    }
}

void     julia(t_fractol f, t_env *e)
{
    f.z_r = e->i.x / e->zoom + e->x_left;
    f.z_i = e->i.y / e->zoom + e->y_floor;
    f.c_r = e->julia.real;
    f.c_i = e->julia.imag;
    while((f.z_r * f.z_r + f.z_i * f.z_i) < 4 && e->iter < e->max_iter)
    {
        f.tmp = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
        f.z_i = 2 * f.z_i * f.z_r + f.c_i;
        f.z_r = f.tmp;
        e->iter++;
    }
}
