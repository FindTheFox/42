/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/01 00:14:09 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void     mandelbrot(t_fractol f, t_env *e)
{
    f.z_r = 0;
    f.z_i = 0;
    f.c_r = e->i.x / e->zoom + e->minx;
    f.c_i = e->i.y / e->zoom + e->miny;
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
    f.z_r = e->i.x / e->zoom + e->minx;
    f.z_i = e->i.y / e->zoom + e->miny;
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

void    lauren(t_fractol f, t_env *e)
{
    f.z_r = 0;
    f.z_i = 0;
    f.c_r = e->i.x / e->zoom + e->x_left;
    f.c_i = e->i.y / e->zoom + e->y_floor;
    while (e->iter < e->max_iter && f.z_i * f.z_i + f.z_r * f.z_r <= 4)
	{
		f.tmp = fabs(f.z_i * f.z_i - f.z_r * f.z_r) + f.c_r;
		f.z_r = 2 * f.z_i * f.z_r + f.c_i;
		f.z_i = f.tmp;
        e->iter++;
	}
}

void	phoenix(t_fractol f, t_env *e)
{
	double	n;
	t_rng	t;

	n = f.z_r * f.z_r + f.z_i * f.z_i;
	t = (t_rng) {.real = 0, .imag = 0};
    f.c_r = e->i.x / e->zoom + e->minx;
    f.c_i = e->i.y / e->zoom + e->miny;
	while (e->iter < e->max_iter && n < 4)
	{
		f.z_i = 2 * fabs(f.z_i * f.z_r) + f.c_i;
		f.z_r = t.real - t.imag - f.c_r;
		t.real = f.z_r * f.z_r;
		t.imag = f.z_i * f.z_i;
		n = t.real + t.imag;
        e->iter++;
	}
}