/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/29 03:32:35 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int        deal_key(int key, t_env *e)
{
    ft_putnbr(key);
    ft_putendl("");
    key == 104 ? help_event(e) : 0;
    key == 65307/*53*/ ? ft_exit(e) : 0;
    key == 99/*8*/ ? switch_pal(e) : 0; 
    key == 106/*38*/ ? change_julia_set(e) : 0;
    
    key == 38 ? event_color(0, e) : 0;
    key == 233 ? event_color(1, e) : 0;
    key == 34 ? event_color(2, e) : 0;
    key == 39 ? event_color(3, e) : 0;
    key == 40 ? event_color(4, e) : 0;
    key == 45 ? event_color(5, e) : 0;
    key == 232 ? event_color(6, e) : 0;
    if (key == 116/*t*/)
        e->switc == 0 ? e->switc = 1 : (e->switc = 0);
    key == 65436/*83*/ ? switch_fractal(e, 0) : 0;
    key == 65433/*84*/ ? switch_fractal(e, 1) : 0;
    key == 65435/*85*/ ? switch_fractal(e, 2) : 0;
    key == 65430/*86*/ ? switch_fractal(e, 3) : 0;
    key == 65437/*87*/ ? switch_fractal(e, 4) : 0;
    key == 65432/*88*/ ? switch_fractal(e, 5) : 0;
    key == 65429/*89*/ ? switch_fractal(e, 6) : 0;
    key == 65431/*91*/ ? switch_fractal(e, 7) : 0;
    key == 65434/*91*/ ? switch_fractal(e, 8) : 0;
    key == 65438/*91*/ ? switch_fractal(e, 9) : 0;    
    //key == 65293/*49*/ ? allow_motion_julia(e) : 0;
    key == 100/*15*/ ? reset_default(e) : 0;
    if(key == 115)
    {
        e->smooth == 0 ? e->smooth += 1 : (e->smooth = 0); 
        do_fractol(e);
    }
    //do_fractol(e);
    return (0); 
}

int         press_event(int key, t_env *e)
{
    key == 65451/*69*/ || key == 65453/*78*/ ? cycle_usr(key, e) : 0;
    key == 114/*15*/ ? rgb_usr(e, 'r') : 0;
    key == 103/*5*/ ? rgb_usr(e, 'g') : 0;
    key == 98/*11*/ ? rgb_usr(e, 'b') : 0;
    key == 65361/*123*/ ? move(e, 'x', 0.05) : 0;
    key == 65363/*124*/ ? move(e, 'x', -0.05) : 0;
    key == 65361/*126*/ ? move(e, 'y', 0.05) : 0;
    key == 65364/*125*/ ? move(e, 'y', -0.05) : 0;
    if (key == 65365 || key == 65366)
    {
        key == 65365 ? e->max_iter += 20 : (e->max_iter -= 20);
        do_fractol(e);
    }    
    return (0);
}

void        cycle_usr(int k, t_env *e)
{
    if (k == 65453)
        e->cycle <= 2 || e->cycle <= 5 ? e->cycle = 2 : (e->cycle -= 5);
    else if (k == 65451)
        e->cycle > 300 ? e->cycle = 0 : (e->cycle += 5);
    //e->cycle < 0 ? e->cycle = 1 : 0;
    ft_putnbr(e->cycle);
    ft_putendl("");
    do_fractol(e);
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
        e->choix = 4;
    else if (c == 5)
        e->choix = 5;
    else if (c == 6)
        e->choix = 6;
    else if (c == 7)
        e->choix = 7;
    else if (c == 8)
        e->choix = 8;
    else if (c == 9)
        e->choix = 9;
    init_fractal(e);
    do_fractol(e);
}

void        switch_pal(t_env *e)
{
    e->usr_color == 5 ? e->usr_color = 0 : e->usr_color++;
    get_pal(e);
    do_fractol(e);
}

void        get_pal(t_env *e)
{
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
}

void        event_color(int key, t_env *e)
{
    if (key == 0)
    {
        get_pal(e);
        e->style_color = 0;
    }
    else if (key == 1)
    {
        e->r = 0x0f;
        e->g = 0x0f;
        e->b = 0x0f;
        e->style_color = 1;
    }
    else if (key == 2)
    {
        e->r = 210;
        e->g = 66;
        e->b = 113;
        e->style_color = 2;
    }
    else if (key == 3)
    {
        e->r = 0x00;
        e->g = 0xc1;
        e->b = 0xe5;
        e->r2 = 0xbf;
        e->g2 = 0x1e;
        e->b2 = 0x00;
        e->style_color = 3;
    }
    key == 4 ? e->style_color = 4 : 0;
    key == 5 ? e->style_color = 5 : 0;
    key == 6 ? e->style_color = 6 : 0;
    do_fractol(e);
}

int        motion_mouse(int x, int y, t_env *e)
{
    if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && e->motion)
	{
		e->julia.real = (x + e->offset.x) / (double)e->zoom + e->minx;
		e->julia.imag = (y + e->offset.y) / (double)e->zoom + e->miny;
		do_fractol(e);
	}
    return (1);
}

void        rgb_usr(t_env *e, char c)
{
    if (e->switc == 0)
    {
        if (c == 'r')
            e->r <= 255  ? e->r += 4 : (e->r = 0);
        else if (c == 'g')
            e->g <= 255 ? e->g += 4 : (e->g = 0);
        else if (c == 'b')
            e->b < 255 ? e->b += 4 : (e->b = 0);
    }
    else if (e->switc == 1 && e->style_color == 3)
    {
        if (c == 'r')
            e->r2 <= 255  ? e->r2 += 4 : (e->r2 = 0);
        else if (c == 'g')
            e->g2 <= 255 ? e->g2 += 4 : (e->g2 = 0);
        else if (c == 'b')
            e->b2 < 255 ? e->b2 += 4 : (e->b2 = 0);
    }
    do_fractol(e);
}

int			mouse_zoom(int k, int x, int y, t_env *e)
{
    ft_putnbr(k);
	if ((k == 1 || k == 3 || k == 4 || k == 5) &&
	(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == 3)
        {
            e->x1 =  (x / e->zoom + e->x1) - (x / (e->zoom / 1.25));
			e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom / 1.25));
            e->max_iter -= 3;
        }
        k == 3 || k == 5 ? e->zoom /= 1.25 : 0;
        if (k == 1)
		{
			e->x1 =  (x / e->zoom + e->x1) - (x / (e->zoom * 1.25));
			e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom * 1.25));
            e->max_iter += 3;
        }
        k == 1 || k == 4 ? e->zoom *= 1.25 : 0;
        do_fractol(e);
	}
	return (1);
}