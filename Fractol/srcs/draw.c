/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/28 23:55:42 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fractol(t_env *e)
{
    t_fractol f;

    e->scalex = (e->x_right - e->x_left) * e->zoom;
    e->scaley = (e->y_top - e->y_floor) * e->zoom;
    e->i.x = -1;
    f.tmp = 0;
    while(++e->i.x < e->scalex)
    {
        e->i.y = -1;
        while(++e->i.y < e->scaley)
            draw_fractol(e, f);
    }
}

void        choose_fractol(t_env *e, t_fractol f)
{
    f.c_r = e->i.x / e->zoom + e->x_left;
    f.c_i = e->i.y / e->zoom + e->y_floor;///
    f.z_r = 0;
    f.z_i = 0;
    if (e->choix = 0)
        mandelbrot(f, e);
    if (e->choix = 1)
        julia(f, e);
    if (f.iter == e->max_iter)
        color_pixel_img(e, e->i.x, e->i.y, 0x849429);
}       

void		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < HEIGHT && x < WITDH)
		env->img[x + WITDH * y] = color;
}