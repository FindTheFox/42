/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:18:31 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 20:42:05 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
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
*/

static t_vec    center(t_vec *out)
{
        out->x *= 0.5f * W_W;
        out->y *= 0.5f * W_H;
        return(*out);
}

t_matrix            init_matrix_world(t_env *e)
{
    float           oldtime;
    static float    fTheta;
    t_matrix        matworld;

    oldtime = e->time;
    e->time = SDL_GetTicks();
    fTheta += (e->time - oldtime) / 1000;
    e->matrotz = init_matrix_rotz(fTheta * 0.5f);
    e->matrotx = init_matrix_rotx(fTheta);
    e->mattranslate = init_matrix_translation(0.0f, 0.0f, 16.0f);
    matworld = init_matrix_identity();
    matworld = matrix_mult_matrix(e->matrotz, e->matrotx);
    matworld = matrix_mult_matrix(e->matworld, e->mattranslate);
    return (matworld);
}

static void        ca_tourne(t_env *e, int i)
{
    e->tritransform.p[0] = matrix_mult_vector(e->matworld, e->tris[i].p[0]);
    e->tritransform.p[1] = matrix_mult_vector(e->matworld, e->tris[i].p[1]);
    e->tritransform.p[2] = matrix_mult_vector(e->matworld, e->tris[i].p[2]);
    // e->tritransform.p[0] = vectordiv(e->tris[i].p[0], e->tris[i].p[0].w);
    // e->tritransform.p[1] = vectordiv(e->tris[i].p[1], e->tris[i].p[1].w);
    // e->tritransform.p[2] = vectordiv(e->tris[i].p[2], e->tris[i].p[2].w);

    // e->tris[i].p[1] = matrix_mult_vector(e->matrotx, e->tris[i].p[1]);
    // e->tris[i].p[2] = matrix_mult_vector(e->matrotx, e->tris[i].p[2]);
    // e->tris[i].p[0] = matrix_mult_vector(e->matrotx, e->tris[i].p[0]);
    // e->tris[i].p[0] = vectordiv(e->tris[i].p[0], e->tris[i].p[0].w);
    // e->tris[i].p[1] = vectordiv(e->tris[i].p[1], e->tris[i].p[1].w);
    // e->tris[i].p[2] = vectordiv(e->tris[i].p[2], e->tris[i].p[2].w);
    // matrix_mult_vect(&rotz.p[0], &e->tris[i].p[0], &e->matrotx);
    // matrix_mult_vect(&rotz.p[1], &e->tris[i].p[1], &e->matrotx);
    // matrix_mult_vect(&rotz.p[2], &e->tris[i].p[2], &e->matrotx);
}

void       lumiere(t_env *e, t_vec normal)
{
    float dp;
    
    e->vlist.light_dir = (t_vec){ 0.0f, 0.0f, -1.0f, 0.0f };
    e->vlist.light_dir = vectornormal(e->vlist.light_dir);
    dp = vectorproduct(normal, e->vlist.light_dir);
    e->triprojected.color = color_shading(0x00ffff, dp);
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
    e->vlist.vcamera = vectorsub(e->tritransform.p[0], e->vlist.vcamera);
    if (vectorproduct(normal, e->vlist.vcamera) < 0)
    {
        lumiere(e, normal);
        return (1);
    }
    return (0);
}

void        cube3d(t_env *env)
{
    int     i;

    env->matworld = init_matrix_world(env);
    env->matproj = init_matrix_proj(env);
    i = -1;
    while (++i < 12)
    {
        ca_tourne(env, i);
        
        //Offset on z axis
        // transl = env->tris[i].p;
        // transl[0].z += 3.0f;
        // transl[1].z += 3.0f;
        // transl[2].z += 3.0f;
        
        //normalize
        if (normalize(env, i))
        {
            //projection
            env->triprojected.p[0] = matrix_mult_vector(env->matproj, env->tritransform.p[0]);
            env->triprojected.p[1] = matrix_mult_vector(env->matproj, env->tritransform.p[1]); 
            env->triprojected.p[2] = matrix_mult_vector(env->matproj, env->tritransform.p[2]);

            env->triprojected.p[0] = vectordiv(env->triprojected.p[0], env->triprojected.p[0].w);
            env->triprojected.p[1] = vectordiv(env->triprojected.p[1], env->triprojected.p[1].w);
            env->triprojected.p[2] = vectordiv(env->triprojected.p[2], env->triprojected.p[2].w); 

            //Scale
            env->triprojected.p[0] = vectoradd(env->triprojected.p[0], env->vlist.voff_set);
            env->triprojected.p[1] = vectoradd(env->triprojected.p[1], env->vlist.voff_set);
            env->triprojected.p[2] = vectoradd(env->triprojected.p[2], env->vlist.voff_set);

            env->triprojected.p[0] = center(&env->triprojected.p[0]);
            env->triprojected.p[1] = center(&env->triprojected.p[1]);
            env->triprojected.p[2] = center(&env->triprojected.p[2]);

            //***draw and rasterize
            fill_triangle(env, env->triprojected, env->triprojected.color);
            //draw_triangle(env, env->tris[i].p);
            SDL_SetRenderDrawColor(env->rend, 0x00, 0x00, 0x00, 0x00);
        }
    }
    sdl_render(env);
}