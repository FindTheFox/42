/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/01 03:31:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        draw(t_env *e, t_fractol f)
{
    e->iter = 0;
    if (e->choix == 0)
        mandelbrot(f, e);
    else if (e->choix == 1)
        julia(f, e);
    else if (e->choix == 2)
        lauren(f, e);
    else if (e->choix == 3)
        phoenix(f, e);
    else if (e->choix == 4)
        burning_ship(f, e);
    color_pixel_img(e, e->i.x, e->i.y, (e->iter <= e->max_iter ?
    e->color[e->iter % e->div] : 0x00000));
}

void    fractol(t_env *e)
{
    t_fractol f;

    e->minx = ((e->offset.x + (WIDTH >> 1)) / (e->zoom / 2)) / -2;//((e->x_right - e->x_left) * e->zoom);
    e->miny = ((e->offset.y + (HEIGHT >> 1)) / (e->zoom / 2)) / -2;//((e->y_top - e->y_floor) * e->zoom);
    f.c_r = e->i.x / e->zoom + e->minx;
    f.c_i = e->i.y / e->zoom + e->miny; 
    e->i.x = -1;
    while(++e->i.x < WIDTH)
    {
        e->i.y = -1;
        while(++e->i.y < HEIGHT)
            draw(e, f);
    }
}

void        do_fractol(t_env *e)
{
    ft_clear_img(e);
    fractol(e);
    mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

void		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < HEIGHT && x < WIDTH)
		env->img[x + WIDTH * y] = color;
}