/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:01:11 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/10 17:12:24 by saneveu          ###   ########.fr       */
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
    key == 125/*65364*/ ? move(e, &e->move_y, V_MV) : 0;
    key == 126/*65362*/ ? move(e, &e->move_y, -V_MV) : 0;
    key == 124/*65363*/ ? move(e, &e->move_x, V_MV) : 0;
    key == 123/*65361*/ ? move(e, &e->move_x, -V_MV) : 0;
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
    if (e->choice_color == 4)
        e->choice_color = 0;
    else
        e->choice_color++;
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

void		reset(t_env *e)
{
	e->rot_x = 0;
	e->rot_y = 0;
	e->rot_z = 0;
	e->move_x = 0;
	e->move_y = 0;
	e->scale = fmin(e->width / 2 / (e->line + e->max_z),
		e->height / 2 / (e->column + e->max_z));
	e->z_height = 0.2;
	draw_img(e);
}
