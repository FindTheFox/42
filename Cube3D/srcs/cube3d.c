/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 01:18:31 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/16 04:36:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
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
*/
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

int       lumiere(t_env *e, t_vec normal)
{
    float dp;
    
    e->vlist.light_dir = vectornormal(e->vlist.light_dir);
    dp = vectorproduct(normal, e->vlist.light_dir);
    return (color_shading(0xffff00, dp));
}

void            init_matrix_world(t_env *e)
{
    t_matrix        matcam;
    float           oldtime;
    static float    fTheta;

    oldtime = e->time;
    e->time = SDL_GetTicks();
    //fTheta += (e->time - oldtime) / 1000;
    fTheta = 1;
    init_matrix_rotz(&e->matrotz, fTheta * 0.5f);
    init_matrix_rotx(&e->matrotx, fTheta);
    init_matrix_roty(&e->matroty, fTheta * 0.8);
    init_matrix_translation(&e->mattranslate, 0.0f, 0.0f, 8.0f);
    //init_matrix_identity(&matworld);
    e->matworld = matrix_mult_matrix(e->matroty, e->matrotx);
    e->matworld = matrix_mult_matrix(e->matworld, e->matrotz);
    e->matworld = matrix_mult_matrix(e->matworld, e->mattranslate);
    e->vlist.lookdir = (t_vec){ 0,0,1 };
    e->vlist.up = (t_vec){ 0,1,0,1 };
    e->vlist.target = vectoradd(e->vlist.vcamera, e->vlist.lookdir);
    pointatmatrix(&matcam, e->vlist.vcamera, e->vlist.target, e->vlist.up);
    quickinversematrix(&e->matview, matcam);
}

t_triangle          matrix_mult_triangle(t_matrix m, t_triangle tri)
{
    t_triangle triout;

    triout.p[0] = matrix_mult_vector(m, tri.p[0]);
    triout.p[1] = matrix_mult_vector(m, tri.p[1]);
    triout.p[2] = matrix_mult_vector(m, tri.p[2]);
    return (triout);
}

int        normalize(t_env *e, t_triangle tri)
{
    t_vec   normal;
    t_vec   line1;
    t_vec   line2;
    t_vec   vcamray;

    line1 = vectorsub(tri.p[1], tri.p[0]);
    line2 = vectorsub(tri.p[2], tri.p[0]);
    normal = vectorcrossprod(line1, line2);
    normal = vectornormal(normal);
    vcamray = vectorsub(tri.p[0], e->vlist.vcamera);
    if (vectorproduct(normal, vcamray) < 0)
        return (lumiere(e, normal));
    return (0);
}

void            clipping(t_env *e, t_triangle tri)
{
    //printf("proj color %x\n", tri.color);
    fill_triangle(e, tri, tri.color);
    //draw_triangle(e, tri);
}

void        projection(t_env *env, t_triangle triprojected, int color)
{
    t_triangle tview;
    //int j;
    tview = matrix_mult_triangle(env->matview, triprojected);

    triprojected = matrix_mult_triangle(env->matproj, tview);
    triprojected.p[0] = vectordiv(triprojected.p[0], triprojected.p[0].w);
    triprojected.p[1] = vectordiv(triprojected.p[1], triprojected.p[1].w);
    triprojected.p[2] = vectordiv(triprojected.p[2], triprojected.p[2].w); 

    //Scale
    triprojected.p[0] = vectoradd(triprojected.p[0], env->vlist.voff_set);
    triprojected.p[1] = vectoradd(triprojected.p[1], env->vlist.voff_set);
    triprojected.p[2] = vectoradd(triprojected.p[2], env->vlist.voff_set);

    triprojected.p[0] = center(&triprojected.p[0]);
    triprojected.p[1] = center(&triprojected.p[1]);
    triprojected.p[2] = center(&triprojected.p[2]);
    triprojected.color = color;
                //***draw and rasterize
    clipping(env, triprojected);
    //env->buffer[j] = triprojected;
    //while (j--)
    //    clipping(env, env->buffer[j]);
}

void        cube3d(t_env *env)
{
    int     i;
    int     j;
    t_triangle triprojected;
    int         color;
    
    init_matrix_world(env);
    i = -1;
    while (++i < env->nbmesh)
    {
        j = -1;
        while (++j < env->mesh[i].size)
        {
            //if (!(env->buffer = (t_triangle *)ft_memalloc(sizeof(t_triangle) * env->mesh[i].size)))
            //    ft_exit(env, "Triangle buffer malloc error", 0);
            triprojected = matrix_mult_triangle(env->matworld, env->mesh[i].tris[j]);
            //normalize
            if ((color = normalize(env, triprojected)))
                projection(env, triprojected, color);
        }
        //free((t_triangle *)env->buffer);
    }
    sdl_render(env);
}
