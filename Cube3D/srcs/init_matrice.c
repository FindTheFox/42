/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:29:46 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 02:30:34 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void        init_matrix_rotz(t_env *e, float theta)
{
    e->matrotz.m[0][0] = cosf(theta);
    e->matrotz.m[0][1] = sinf(theta);
    e->matrotz.m[1][0] = -sinf(theta);
    e->matrotz.m[1][1] = cosf(theta);
    e->matrotz.m[2][2] = 1;
    e->matrotz.m[3][3] = 1;
}

void        init_matrix_rotx(t_env *e, float theta)
{
    e->matrotx.m[0][0] = 1;
    e->matrotx.m[1][1] = cosf(theta * 0.5f);
    e->matrotx.m[1][2] = sinf(theta * 0.5f);
    e->matrotx.m[2][1] = -sinf(theta * 0.5f);
    e->matrotx.m[2][2] = cosf(theta * 0.5f);
    e->matrotx.m[3][3] = 1;
}

void        init_matrix(t_env *e)
{
    float   fNear;
    float   fFar;
    float   fFov;
    float   fAspectRatio;
    float   fFovRad;

    fNear = 0.1f;
    fFar = 1000.0f;
    fFov = 90.0f;
    fAspectRatio = (float)W_W / (float)W_H;
    fFovRad = 1.0f / tanf(fFov * 0.5 / 180 * 3.14159f);

    e->matproj.m[0][0] = fAspectRatio * fFovRad;
    e->matproj.m[1][1] = fFovRad;
    e->matproj.m[2][2] = fFar / (fFar - fNear);
    e->matproj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    e->matproj.m[2][3] = 1.0f;
    e->matproj.m[3][3] = 0.0f;
}
