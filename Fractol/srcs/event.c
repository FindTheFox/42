/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/07 16:23:30 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int deal_key(int key, t_env *e)
{
    ft_putnbr(key);
    ft_putendl("");
    key == 4 ? help_event(e) : 0;
    key == 53 ? ft_exit(e) : 0;
    key == 8 ? switch_pal(e) : 0;
    key == 38 ? change_julia_set(e) : 0;

    key == 18 ? event_color(0, e) : 0;
    key == 19 ? event_color(1, e) : 0;
    key == 20 ? event_color(2, e) : 0;
    key == 21 ? event_color(3, e) : 0;
    key == 23 ? event_color(4, e) : 0;
    key == 22 ? event_color(5, e) : 0;
    key == 26 ? event_color(6, e) : 0;
    if (key == 17)
        e->switc == 0 ? e->switc = 1 : (e->switc = 0);
    key == 83 ? switch_fractal(e, 0) : 0;
    key == 84 ? switch_fractal(e, 1) : 0;
    key == 85 ? switch_fractal(e, 2) : 0;
    key == 86 ? switch_fractal(e, 3) : 0;
    key == 87 ? switch_fractal(e, 4) : 0;
    key == 88 ? switch_fractal(e, 5) : 0;
    key == 89 ? switch_fractal(e, 6) : 0;
    key == 91 ? switch_fractal(e, 7) : 0;
    key == 92 ? switch_fractal(e, 8) : 0;
    key == 82 ? switch_fractal(e, 9) : 0;
    key == 46 ? allow_motion_julia(e) : 0;
    key == 2 ? reset_default(e) : 0;
    if (key == 1)
    {
        e->smooth == 0 ? e->smooth += 1 : (e->smooth = 0);
        do_fractol(e);
    }
    return (0);
}

int press_event(int key, t_env *e)
{
    key == 69 || key == 78 ? cycle_usr(key, e) : 0;
    key == 15 ? rgb_usr(e, 'r') : 0;
    key == 5 ? rgb_usr(e, 'g') : 0;
    key == 11 ? rgb_usr(e, 'b') : 0;
    key == 123 ? move(e, 'x', 0.05) : 0;
    key == 124 ? move(e, 'x', -0.05) : 0;
    key == 126 ? move(e, 'y', 0.05) : 0;
    key == 125 ? move(e, 'y', -0.05) : 0;
    if (key == 116 || key == 121)
    {
        key == 116 ? e->max_iter += 42 : (e->max_iter -= 42);
        do_fractol(e);
    }
    return (0);
}

void switch_fractal(t_env *e, int c)
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
