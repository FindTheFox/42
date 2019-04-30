/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/01 00:37:05 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int        deal_key(int key, t_env *e)
{
    //ft_putnbr(key);
    //ft_putchar('\n');
    key == 65307 ? ft_exit(e) : 0;
    key == 99 ? switch_color(e) : 0;
    key == 65451 ? zoom(e, ZOOM) : 0;
    key == 65453 ? zoom(e, -ZOOM) : 0;
    key == 106 ? change_julia_set(e) : 0;
    key == 65436 ? switch_fractal(e, 0) : 0;
    key == 65433 ? switch_fractal(e, 1) : 0;
    key == 65435 ? switch_fractal(e, 2) : 0;
    key == 65430 ? switch_fractal(e, 3) : 0;
    do_fractol(e);
    return (0); 
}

void        event(t_env *e)
{
    mlx_key_hook(e->win_ptr, deal_key, e); /*simple push button*/
    mlx_hook(e->win_ptr, 1, 1 << 8, motion_mouse, e); /*change set when mouse moving*/
    mlx_hook(e->win_ptr, 17, (1L << 17), ft_exit, e); /*if win close by the cross*/
}

void        switch_fractal(t_env *e, int c)
{
    if (c == 0)
        e->choix = 0;
    if (c == 1)
        e->choix = 1;
    if (c == 2)
        e->choix = 2;
    if (c == 3)
        e->choix = 3;
    init_fractal(e);
}

void        switch_color(t_env *e)
{
    e->usr_color == 4 ? e->usr_color = 0 :
        e->usr_color++;
    if (e->usr_color == 0)
        colorset0(e);
    if (e->usr_color == 1)
        colorset1(e);
    if (e->usr_color == 2)
        colorset2(e);
    if (e->usr_color == 3)
        colorset3(e);
    if (e->usr_color == 4)
        colorset4(e);
}

void        zoom(t_env *e, int speed)
{
    e->zoom += speed;
}

void        change_julia_set(t_env *e)
{
    e->rng == 5 ? e->rng = 0 : e->rng++;
    julias_changes(e);
}

int        motion_mouse(int x, int y, t_env *e)
{
    if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && !e->motion)
	{
		e->julia.real = (x + e->offset.x) / (double)e->zoom + e->minx;
		e->julia.imag = (y + e->offset.y) / (double)e->zoom + e->miny;
		do_fractol(e);
	}
    return (1);
}