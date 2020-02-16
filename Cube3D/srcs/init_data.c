/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:22:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/15 18:43:46 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    init_data(t_env *e)
{
    e->fNear = 0.1f;
    e->fFar = 1000.0f;
    e->fFov = 90.0f;
    e->fAspectRatio = (float)W_W / (float)W_H;
    e->fFovRad = 1.0f / tanf(e->fFov * 0.5 / 180 * 3.14159f);
    e->vlist.voff_set = (t_vec){ 1,1,0,1 };
    e->vlist.light_dir = (t_vec){ 0.0f, 0.0f, -1.0f, 1.0f };
    e->xtheta = 1;
    e->ytheta = 1;
    e->ztheta = 1;
    e->zoom = 3;
    init_matrix_rotx(&e->matrotx, e->xtheta);
    init_matrix_roty(&e->matroty, e->ytheta);
    init_matrix_rotz(&e->matrotz, e->ztheta);
    init_matrix_proj(e);
    init_matrix_translation(&e->mattranslate, 0, 0, e->zoom);
}