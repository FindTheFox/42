/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/11 20:40:10 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void     mandelbrot(t_fractol f, t_env *e)
{
    //f.c_r = 1.5 * (e->i.x - WIDTH / 2)
            //(0.5 * e->zoom * WIDTH) + e->offset.x;//e->i.x / e->zoom + e->minx;
    //f.c_i = (e->i.y - HEIGHT / 2)
            //(0.5 * e->zoom * HEIGHT) + e->offset.y;
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
    while (e->iter < e->max_iter && f.z_i * f.z_i + f.z_r * f.z_r <= 4)
	{
		f.tmp = fabs(f.z_i * f.z_i - f.z_r * f.z_r) + f.c_r;
		f.z_r = 2 * f.z_i * f.z_r + f.c_i;
		f.z_i = f.tmp;
        e->iter++;
	}
}

void    burning_ship(t_fractol f, t_env *e)
{
	while (e->iter++ < e->max_iter && f.z_r * f.z_r + f.z_i * f.z_i < 4)
    {
        f.tmp = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
		f.z_i = fabs(2 * f.z_r * f.z_i) + f.c_i;
		f.z_r = f.tmp;
    }
}

void	phoenix222(t_fractol f, t_env *e)
{
	double	ti;
    double  tr;
    double  zi_old;
    double  zr_old;

    zi_old = 0;
    zr_old = 0;
   
	while (e->iter++ < e->max_iter && f.z_r * f.z_r + f.z_i * f.z_i < 4)
	{
        ti = 2 * f.z_r * f.z_i + f.c_i * zi_old;
        tr = f.z_r * f.z_r - (f.z_i * f.z_i) + f.c_i * zr_old + f.c_r;
        zr_old = f.z_r;
        zi_old = f.z_i;
        f.z_r = tr;
        f.z_i = ti;
	}
}

void	phoenix(t_fractol f, t_env *e)
{
	double	ti;
    double  tr;

    f.z_r = 0;
    f.z_i = 0;
	while (e->iter++ < e->max_iter && f.z_r * f.z_r + f.z_i * f.z_i < 4)
	{
		f.z_i = 2 * f.z_i * f.z_r + f.c_i;
		f.z_r = tr - ti - f.c_r;
        tr = f.z_r * f.z_r;
        ti = f.z_i * f.z_i;
	}
}


void    tricorn(t_fractol f, t_env *e)
{
    t_rng   old;

    f.z_r = 0;
    f.z_i = 0;
    f.c_r = e->i.x / e->zoom + e->minx;
    f.c_i = e->i.y / e->zoom + e->miny;
    while(e->iter++ > e->max_iter)
    {
        old.real = f.z_r;
		old.imag = f.z_i;
		f.z_r = old.real * old.real - old.imag * old.imag + f.c_r;
		f.z_i = -2 * old.real * old.imag + f.c_i;
		if (f.z_r * f.z_r + f.z_i * f.z_i > 4)
			break ;
    }
}