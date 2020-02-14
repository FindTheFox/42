/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:57:46 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 02:56:20 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../SDL/SDL.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

# define W_W 800
# define W_H 800

typedef struct      s_rgba
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
}                   t_rgba;

typedef struct      s_vec
{
    float   x;
    float   y;
    float   z;
}                   t_vec;

typedef struct      s_triangle
{
    t_vec   p[3];
    int     color;
}                   t_triangle;

typedef struct      s_mesh
{
    t_triangle      *tris;
    int             size;
}                   t_mesh;

typedef struct      s_matrix
{
    float           m[4][4];
}                   t_matrix;

typedef struct      s_fill 
{
    int           yend;
    int           xend;
    int           ystart;
    int           xstart;
    float         m0;
    float         m1;
    float         x1;
    float         x0;
}                   t_fill;

typedef struct      s_vlist
{
    t_vec           vcamera;
    t_vec           light_dir;
}                   t_vlist;

typedef struct      s_env
{
    float           fps;
    float           time;
    float           frametime;
    t_vlist         vlist;
    t_fill          fill;
    t_matrix        matproj;
    t_matrix        matrotz;
    t_matrix        matrotx;
    t_matrix        matroty;
    t_triangle      tris[12];
    t_mesh          mesh;
    t_rgba          rgba;
    SDL_Window      *window;
    SDL_Event       event;
    SDL_Renderer    *rend;
    SDL_Texture     *screen;
    SDL_Surface     *winsurf;
}                   t_env;

/*
**Global
*/

void        cube3d(t_env *env);
void        ft_exit(t_env *env, char *s, int flag);
void        init_cube(t_env *env);
void        init_sdl(t_env *env);

void        sdl_render(t_env *e);

/*
**Matrice calcul and init
*/

void        matrix_mult_vect(t_vec *i, t_vec *o, t_matrix *m);
void        init_matrix(t_env *e);
void        init_matrix_rotx(t_env *e, float theta);
void        init_matrix_rotz(t_env *e, float theta);

/*
**Vector calcul
*/

t_vec           vectoradd(t_vec v1, t_vec v2);
t_vec           vectorsub(t_vec v1, t_vec v2);
float           vectorproduct(t_vec v1, t_vec v2);
t_vec           vectornormal(t_vec v);
t_vec           vectorcrossprod(t_vec v1, t_vec v2);
t_vec           vectordiv(t_vec v, float a);
t_vec           vectormult(t_vec v, float a);
float           vectorlen(t_vec v);

/*
**Triangle Draw
*/

void        fill_triangle(t_env *e, t_triangle tri, int color);
void        draw_triangle(t_env *e, t_vec p[3]);

void        put_pixel(t_env *e, int x, int y, int color);

/*
**Events
*/

void        event(t_env *env);

void        back_to_env(t_env *e, t_vec vec[3], int i);

/*
**Color
*/

t_rgba      hex_to_rgba(int c);
int         rgba_to_hex(t_rgba rgba);
int         color_shading(int color, float shade);

#endif