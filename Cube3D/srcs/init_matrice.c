/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:29:46 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 19:49:25 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_matrix        init_matrix_rotz(float theta)
{
    t_matrix m;

    m.m[0][0] = cosf(theta);
    m.m[0][1] = sinf(theta);
    m.m[1][0] = -sinf(theta);
    m.m[1][1] = cosf(theta);
    m.m[2][2] = 1;
    m.m[3][3] = 1;
    return (m);
}

t_matrix        init_matrix_rotx(float theta)
{
    t_matrix m;

    m.m[0][0] = 1;
    m.m[1][1] = cosf(theta);
    m.m[1][2] = sinf(theta);
    m.m[2][1] = -sinf(theta);
    m.m[2][2] = cosf(theta);
    m.m[3][3] = 1;
    return (m);
}

t_matrix        init_matrix_roty(float theta)
{
    t_matrix m;

    m.m[0][0] = cosf(theta);
    m.m[0][2] = sinf(theta);
    m.m[2][0] = -sinf(theta);
    m.m[1][1] = 1.0f;
    m.m[2][2] = cosf(theta);
    m.m[3][3] = 1.0f;
    return (m);
}

t_matrix        init_matrix_translation(float x, float y, float z)
{
    t_matrix m;

    m.m[0][0] = 1.0f;
    m.m[1][1] = 1.0f;
    m.m[2][2] = 1.0f;
    m.m[3][3] = 1.0f;
    m.m[3][0] = x;
    m.m[3][1] = y;
    m.m[3][2] = z;
    return (m);
}

t_matrix    init_matrix_identity(void)
{
    t_matrix m;

    m.m[0][0] = 1.0f;
    m.m[1][1] = 1.0f;
    m.m[2][2] = 1.0f;
    m.m[3][3] = 1.0f;
    return (m);
}

t_matrix        init_matrix_proj(t_env *e)
{
    t_matrix m;

    m.m[0][0] = e->fAspectRatio * e->fFovRad;
    m.m[1][1] = e->fFovRad;
    m.m[2][2] = e->fFar / (e->fFar - e->fNear);
    m.m[3][2] = (-e->fFar * e->fNear) / (e->fFar - e->fNear);
    m.m[2][3] = 1.0f;
    m.m[3][3] = 0.0f;
    return (m);
}

t_matrix        matrix_mult_matrix(t_matrix m1, t_matrix m2)
{
    t_matrix m;
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            m.m[j][i] = m1.m[j][0] * m2.m[0][i] + m1.m[j][1] * m2.m[1][i] + m1.m[j][2] * m2.m[2][i] + m1.m[j][3] * m2.m[3][i];
    }
    return (m);
}
