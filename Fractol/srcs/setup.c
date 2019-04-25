/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:20:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/25 05:38:49 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    setup(t_env *e)
{
    e->mlx_ptr = mlx_init();
    e->win_ptr = mlx_new_window(e->mlx_ptr, WITDH, HEIGHT, "Fractol");
    e->img_ptr = mlx_new_image(e->mlx_ptr, WITDH, HEIGHT);
    e->img = (int *)mlx_get_data_addr(e->img_ptr, &e->bpp, &e->s_l, &e->endian);
    e->x_left = -2.1;
    e->x_right = 0.6;
    e->y_floor = -1.2;
    e->y_top = 1.2;
    e->zoom = 400;
    e->scalex = (e->x_right - e->x_left) * e->zoom;
    e->scaley = (e->y_top - e->y_floor) * e->zoom;
    e->max_iter = 80;
}