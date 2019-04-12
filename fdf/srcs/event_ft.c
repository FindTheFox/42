/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:59:44 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/12 17:37:08 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_env *e, double *axe, double pixel)
{
	*axe += pixel;
	draw_img(e);
}

void	para(t_env *e)
{
	e->rot_x = 5;
	e->rot_y = 0;
	e->rot_z = 0;
	draw_img(e);
}

void	iso(t_env *e)
{
	e->rot_x = 65;
	e->rot_y = 30;
	e->rot_z = 0;
	draw_img(e);
}

void	hauteur(t_env *e, double z_speed)
{
	e->z_height += z_speed;
	draw_img(e);
}

void	zoom(t_env *e, int zoom)
{
	if (!(e->scale + zoom <= 0))
		e->scale += zoom;
	draw_img(e);
}
