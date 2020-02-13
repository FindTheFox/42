/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:59:44 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 03:45:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void        matrix_mult_vect(t_vec *i, t_vec *o, t_matrix *m)
{
    float w;

    o->x = i->x * m->m[0][0] + i->y * m->m[1][0] + i->z * m->m[2][0] + m->m[3][0];
    o->y = i->x * m->m[0][1] + i->y * m->m[1][1] + i->z * m->m[2][1] + m->m[3][1];
    o->z = i->x * m->m[0][2] + i->y * m->m[1][2] + i->z * m->m[2][2] + m->m[3][2];
    w = i->x * m->m[0][3] + i->y * m->m[1][3] + i->z * m->m[2][3] + m->m[3][3];

    if (w != 0.0f)
    {
        o->x /= w;
        o->y /= w;
        o->z /= w;
    }
}

static void    center(t_vec *out)
{
        out->x += 1.0f;
        out->y += 1.0f;

        out->x *= 0.5f * W_W;
        out->y *= 0.5f * W_H;
}

static void        ca_tourne(t_env *e, int i)
{
    float           oldtime;
    static float    fTheta;
    t_triangle      rotz;

    oldtime = e->time;
    e->time = SDL_GetTicks();
    fTheta += (e->time - oldtime) / 1000;
    init_matrix_rotz(e, fTheta);
    init_matrix_rotx(e, fTheta);

    matrix_mult_vect(&e->tris[i].p[0], &rotz.p[0], &e->matrotz);
    matrix_mult_vect(&e->tris[i].p[1], &rotz.p[1], &e->matrotz);
    matrix_mult_vect(&e->tris[i].p[2], &rotz.p[2], &e->matrotz);

    matrix_mult_vect(&rotz.p[0], &e->tris[i].p[0], &e->matrotx);
    matrix_mult_vect(&rotz.p[1], &e->tris[i].p[1], &e->matrotx);
    matrix_mult_vect(&rotz.p[2], &e->tris[i].p[2], &e->matrotx);
}

int        cross_product(t_env *e, int i)
{
    t_vec   normal;
    t_vec   line1;
    t_vec   line2;
    float   l;

    line1.x = e->tris[i].p[1].x - e->tris[i].p[0].x;
    line1.y = e->tris[i].p[1].y - e->tris[i].p[0].y;
    line1.z = e->tris[i].p[1].z - e->tris[i].p[0].z;

    line2.x = e->tris[i].p[2].x - e->tris[i].p[0].x;
    line2.y = e->tris[i].p[2].y - e->tris[i].p[0].y;
    line2.z = e->tris[i].p[2].z - e->tris[i].p[0].z;

    normal.x = line1.y * line2.z - line1.z * line2.y;
    normal.y = line1.z * line2.x - line1.x * line2.z;
    normal.z = line1.x * line2.y - line1.y * line2.x;

    l = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    normal.x /= l;
    normal.y /= l;
    normal.z /= l;
    //if (normal.z < 0)
    if (normal.x * (e->tris[i].p[0].x - e->vcamera.x) +
    normal.y * (e->tris[i].p[0].y - e->vcamera.y) +
    normal.z * (e->tris[i].p[0].z - e->vcamera.z) < 0)
        return (1);
    return (0);
}

void        cube3d(t_env *env)
{
    int     i;
    t_vec   out[3];
    t_vec   *transl;

    SDL_SetRenderDrawColor(env->rend, 0, 0, 0, 0);
    SDL_RenderClear(env->rend);
    init_cube(env);
    init_matrix(env);
    i = -1;
    while (++i < 12)
    {
        ca_tourne(env, i);
        
        //Offset on z axis
        transl = env->tris[i].p;
        transl[0].z += 3.0f;
        transl[1].z += 3.0f;
        transl[2].z += 3.0f;
        
        //normalize
        if (cross_product(env, i))
        {
            //projection
            matrix_mult_vect(&env->tris[i].p[0], &out[0], &env->matproj);
            matrix_mult_vect(&env->tris[i].p[1], &out[1], &env->matproj); 
            matrix_mult_vect(&env->tris[i].p[2], &out[2], &env->matproj);

            //Scale
            center(&out[0]);
            center(&out[1]);
            center(&out[2]);

            //draw and rasterize
            SDL_SetRenderDrawColor(env->rend, 0xff, 0x00, 0x00, 0xff);
            draw_triangle(env, out);
        }
    }
    SDL_RenderPresent(env->rend);
}

int         main(void)
{
    t_env   env;

    ft_memset(&env, 0, sizeof(t_env));
    init_sdl(&env);
    while (1)
    {
        cube3d(&env);
        event(&env);
    }
    return (0);
}

