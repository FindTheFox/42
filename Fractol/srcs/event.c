/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/21 19:11:43 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int        deal_key(int key, t_env *e)
{
    ft_putnbr(key);
    ft_putchar('\n');
    key == /*65307*/53 ? ft_exit(e) : 0;
    key == /*99*/8 ? switch_color(e) : 0;
    key == /*65451*/69 ? zoom(e, ZOOM) : 0;
    key == /*65453*/78 ? zoom(e, -ZOOM) : 0;
    key == /*106*/38 ? change_julia_set(e) : 0;
    key == /*65436*/83 ? switch_fractal(e, 0) : 0;
    key == /*65433*/84 ? switch_fractal(e, 1) : 0;
    key == /*65435*/85 ? switch_fractal(e, 2) : 0;
    key == /*65430*/86 ? switch_fractal(e, 3) : 0;
    key == /*65437*/87 ? switch_fractal(e, 4) : 0;
    key == /*654328*/88 ? switch_fractal(e, 5) : 0;
    key == /*65429*/89 ? switch_fractal(e, 6) : 0;
    key == /*65431*/91 ? switch_fractal(e, 7) : 0;
    key == /*1148*/15 ? rgb_usr(e, 'r') : 0;
    key == /*103*/5 ? rgb_usr(e, 'g') : 0;
    key == /*98*/11 ? rgb_usr(e, 'b') : 0;
    key == /*65365*/116 ? e->max_iter += 10 : 0;
    key == /*65366*/121 ? e->max_iter -= 10 : 0;
    key == 65361 ? move(e, 'x', -40) : 0;
    key == 65363 ? move(e, 'x', 40) : 0;
    key == 65361 ? move(e, 'y', 40) : 0;
    key == 65364 ? move(e, 'y', -40) : 0;
    key == 15 ? reset(e) : 0;
    do_fractol(e);
    return (0); 
}

void        reset(t_env *e)
{
    e->zoom = 200;
    e->offset = (t_index) {.x = 0, .y = 0}; 
}

void        switch_fractal(t_env *e, int c)
{
    if (c == 0)
        e->choix = 0;
    else if (c == 1)
        e->choix = 1;
    else if (c == 2)
        e->choix = 2;
    else if (c == 3)
        e->choix = 3;
    else if (c == 4)
    {
        e->choix = 4;
        //e->offset = (t_index) {.x = 500, .y = 1000};
    }
    else if (c == 5)
        e->choix = 5;
    else if (c == 6)
        e->choix = 6;
    else if (c == 7)
        e->choix = 7;
    init_fractal(e);
}

void        switch_color(t_env *e)
{
    e->usr_color == 6 ? e->usr_color = 0 :
        e->usr_color++;
    if (e->usr_color == 0)
        colorset0(e);
    else if (e->usr_color == 1)
        colorset1(e);
    else if (e->usr_color == 2)
        colorset2(e);
    else if (e->usr_color == 3)
        colorset3(e);
    else if (e->usr_color == 4)
        colorset4(e);
    else if (e->usr_color == 5)
        colorset5(e);
    else if (e->usr_color == 6)
    {
        !e->r ? e->r = 1 : 0;
        !e->g ? e->g = 1 : 0;
        !e->b ? e->b = 1 : 0;
    }
}

void        zoom(t_env *e, int speed)
{
    e->zoom += speed;
}

void        change_julia_set(t_env *e)
{
    e->rng == 6 ? e->rng = 0 : e->rng++;
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

void        rgb_usr(t_env *e, char c)
{
    if (c == 'r')
        e->r += 1;
    else if (c == 'g')
        e->g += 1;
    else if (c == 'b')
        e->g += 1;
}

void        move(t_env *e, char c, int m)
{
    if (c == 'x')
        e->offset.x += m;
    else if (c == 'y')
        e->offset.y += m;
}

int			mouse_zoom(int k, int x, int y, t_env *e)
{
	float	scaling;
    
    scaling = 0;
	if ((k == 1 || k == 3 || k == 4 || k == 5) &&
	(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == 4 || k == 1)
			scaling = 1.25;
		else if (k == 5 || k == 3)
			scaling = -1.25;
		if (k == 1 || k == 3)
		{
			e->offset.x = round(e->offset.x + ((WIDTH >> 1) - x) * scaling);
			e->offset.y = round(e->offset.y + ((HEIGHT >> 1) - y) * scaling);
            printf("x1 = %f\n", e->offset.x);
            printf("y1 = %f\n", e->offset.y);
        }
		e->zoom *= scaling;
        do_fractol(e);
	}
	return (1);
}