/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:18:31 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/15 20:04:26 by saneveu          ###   ########.fr       */
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

static t_vec    center(t_vec *out)
{
        out->x += 1.0f;
        out->y += 1.0f;

        out->x *= 0.5f * W_W;
        out->y *= 0.5f * W_H;
        return(*out);
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

void       lumiere(t_env *e, t_vec normal, int i)
{
    float dp;
    
    e->vlist.light_dir = (t_vec){ 0.0f, 0.0f, -1.0f };
    e->vlist.light_dir = vectornormal(e->vlist.light_dir);
    dp = vectorproduct(normal, e->vlist.light_dir);
    e->tris[i].color = color_shading(0x00ffff, dp);
}

int        normalize(t_env *e, int i)
{
    t_vec   normal;
    t_vec   line1;
    t_vec   line2;

    line1 = vectorsub(e->tris[i].p[1], e->tris[i].p[0]);
    line2 = vectorsub(e->tris[i].p[2], e->tris[i].p[0]);
    normal = vectorcrossprod(line1, line2);
    normal = vectornormal(normal);
    if (normal.x * (e->tris[i].p[0].x - e->vlist.vcamera.x) +
    normal.y * (e->tris[i].p[0].y - e->vlist.vcamera.y) +
    normal.z * (e->tris[i].p[0].z - e->vlist.vcamera.z) < 0)
    {
        lumiere(e, normal, i);
        return (1);
    }
    return (0);
}

void        cube3d(t_env *env)
{
    int     i;
    t_vec   out[3];
    t_vec   *transl;

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
        printf("x = %f || y = %f || z = %f\n", env->tris[i].p[0].x, env->tris[i].p[0].y, env->tris[i].p[0].z); 
 
        //normalize
        if (normalize(env, i))
        {
            //projection
            matrix_mult_vect(&env->tris[i].p[0], &out[0], &env->matproj);
            matrix_mult_vect(&env->tris[i].p[1], &out[1], &env->matproj); 
            matrix_mult_vect(&env->tris[i].p[2], &out[2], &env->matproj);

            //Scale
            env->tris[i].p[0] = center(&out[0]);
            env->tris[i].p[1] = center(&out[1]);
            env->tris[i].p[2] = center(&out[2]);

            //***draw and rasterize
            fill_triangle(env, env->tris[i], env->tris[i].color);
            //draw_triangle(env, env->tris[i].p);
            SDL_SetRenderDrawColor(env->rend, 0x00, 0x00, 0x00, 0x00);
        }
    }
    sdl_render(env);
}
