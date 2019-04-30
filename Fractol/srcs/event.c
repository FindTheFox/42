/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/30 07:02:10 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int        deal_key(int key, t_env *e)
{
    //ft_putnbr(key);
    key == 65307 ? ft_exit(e) : 0;
    key == 99 ? change_la_couleur(e) : 0;
    key == 65451 ? zoom(e, ZOOM) : 0;
    key == 65453 ? zoom(e, -ZOOM) : 0;
    key == 106 ? change_julia_set(e) : 0;
    return (0); 
}

void        event(t_env *e)
{
    mlx_key_hook(e->win_ptr, deal_key, e);
    mlx_hook(e->win_ptr, 17, (1L << 17), ft_exit, e);
}

void        change_la_couleur(t_env *e)
{
    e->usr_color == 2 ? e->usr_color = 0 :
        e->usr_color++;
    if (e->usr_color == 0)
        colorset0(e);
    if (e->usr_color == 1)
        colorset1(e);
    if (e->usr_color == 2)
        colorset2(e);
    do_fractol(e);
}

void        zoom(t_env *e, int speed)
{
    e->zoom += speed;
    do_fractol(e);
}

void        change_julia_set(t_env *e)
{
    e->rng == 5 ? e->rng = 0 : e->rng++;
    julias_changes(e);
    do_fractol(e);
}