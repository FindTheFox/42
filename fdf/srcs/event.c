/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:01:11 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/02 18:22:19 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         rota_event(int key, t_env *e)
{
    key == 91/*65433*/ ? rotate(e, &e->rot_x, -V_ROT) : 0;	
    key == 84/*65431*/ ? rotate(e, &e->rot_x, V_ROT) : 0;
    key == 88/*654308*/ ? rotate(e, &e->rot_y, V_ROT) : 0;	
    key == 86/*65432*/ ? rotate(e, &e->rot_y, -V_ROT) : 0;	
    key == 89 ? rotate(e, &e->rot_z, -V_ROT_Z) : 0;	
    key == 92/*65434*/ ? rotate(e, &e->rot_z, V_ROT_Z) : 0;	
    key == 69/*65451*/ ? zoom(e, V_ZOOM) : 0;	
    key == 78/*65453*/ ? zoom(e, -V_ZOOM) : 0;	
    key == 125/*65364*/ ? move_y(e, V_MV) : 0;
    key == 126/*65362*/ ? move_y(e, -V_MV) : 0;
    key == 124/*65363*/ ? move_x(e, V_MV) : 0;
    key == 123/*65361*/ ? move_x(e, -V_MV) : 0;
    key == 116/*65365*/ ? hauteur(e, V_Z_HEIGHT) : 0;
    key == 121/*65366*/ ? hauteur(e, -V_Z_HEIGHT) : 0;
    return (0);
}

int 	    deal_key(int key, t_env *e)
{
    key == /*653078*/53 ? end_program(e) : 0;
    key == 15 ? reset(e) : 0;
    key == 34 ? iso(e) : 0;
    key == 35 ? para(e) : 0;
    key == 8 ? color_event(e) : 0;
    return (0);
}

void        color_event(t_env *e)
{
    if (e->choice_color == 3)
        e->choice_color = 0;
    else
        e->choice_color++;
    draw_img(e);
}

void        para(t_env *e)
{
    e->rot_x = 5;
    e->rot_y = 0;
    e->rot_z = 0;
    draw_img(e);
}

void        iso(t_env *e)
{
    e->rot_x = 65;
    e->rot_y = 30;
    e->rot_z = 0;
    draw_img(e);
}

void        hauteur(t_env *e, double z_speed)
{
    e->z_height += z_speed;
    printf("z_height = %f\n", e->z_height);
    draw_img(e);
}

void        zoom(t_env *e, int zoom)
{
    if (!(e->scale + zoom <= 0))
        e->scale += zoom;
    draw_img(e);
} 

void        rotate(t_env *e, double *axe, double degree)
{
    double d;

    d = *axe + degree;
    if (d < 0)
        *axe = 360 + d;
    else
        *axe = d < 360 ? d : d - 360;
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
