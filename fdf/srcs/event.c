/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:01:11 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/24 10:23:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	    deal_key(int key, t_env *e)
{
    ft_putnbr(key);
    ft_putchar('\n');
    key == 65307 ? end_program(e) : 0;
    key == 114 ? reset(e) : 0;
    key == 65433 ? rotate(e, &e->rot_x, -V_ROT) : 0;	
    key == 65431 ? rotate(e, &e->rot_x, V_ROT) : 0;
    key == 65430 ? rotate(e, &e->rot_y, V_ROT) : 0;	
    key == 65432 ? rotate(e, &e->rot_y, -V_ROT) : 0;	
    key == 65429 ? rotate(e, &e->rot_z, -V_ROT_Z) : 0;	
    key == 65434 ? rotate(e, &e->rot_z, V_ROT_Z) : 0;	
    key == 65451 ? zoom(e, V_ZOOM) : 0;	
    key == 65453 ? zoom(e, -V_ZOOM) : 0;	
    key == 65364 ? move_y(e, V_MV) : 0;
    key == 65362 ? move_y(e, -V_MV) : 0;
    key == 65363 ? move_x(e, V_MV) : 0;
    key == 65361 ? move_x(e, -V_MV) : 0;
    key == 65365 ? hauteur(e, V_Z_HEIGHT) : 0;
    key == 65366 ? hauteur(e, -V_Z_HEIGHT) : 0;
    key == 105 ? iso(e) : 0;
    key == 112 ? para(e) : 0;

    return (0);
}

void        para(t_env *e)
{
    e->rot_x = 55;
    e->rot_y = 0;
    e->rot_z = 0;
    draw_img(e);
}

void        iso(t_env *e)
{
    e->rot_x = 120;
    e->rot_y = 120;
    e->rot_z = 120;
    draw_img(e);
}

void        hauteur(t_env *e, double z_speed)
{
    e->z_height += z_speed;
    draw_img(e);
}

void        zoom(t_env *e, int zoom)
{
    if (!(e->scale + zoom < 0))
        e->scale += zoom;
    draw_img(e);
} 

void        rotate(t_env *e, double *axe, double degree)
{
    double d;

    d = *axe + degree;
    if (d >= 360)
        *axe = 0;
    else if (d <= 0)
        *axe = 355;
    else
        *axe = d;
    draw_img(e);
}

void        move_x(t_env *e, double pixel)
{
    e->move_x += pixel;
    draw_img(e);
}

void        move_y(t_env *e, double pixel)
{
    e->move_y += pixel;
    draw_img(e);
}
