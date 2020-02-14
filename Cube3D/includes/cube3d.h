/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:57:46 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 20:27:12 by saneveu          ###   ########.fr       */
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
    float   w;
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
    t_vec           voff_set;
}                   t_vlist;

typedef struct      s_env
{
    float           fNear;
    float           fFar;
    float           fFov;
    float           fAspectRatio;
    float           fFovRad;
    float           fps;
    float           time;
    float           frametime;
    t_vlist         vlist;
    t_fill          fill;
    t_matrix        matworld;
    t_matrix        matproj;
    t_matrix        matrotz;
    t_matrix        matrotx;
    t_matrix        matroty;
    t_matrix        mattranslate;
    t_triangle      tris[12];
    t_triangle      tritransform;
    t_triangle      triprojected;
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
void        init_data(t_env *e);
void        sdl_render(t_env *e);

/*
**Matrice calcul and init
*/

t_matrix        init_matrix_proj(t_env *e);
t_matrix        init_matrix_rotx(float theta);
t_matrix        init_matrix_rotz(float theta);
t_matrix        init_matrix_roty(float theta);
t_matrix        matrix_mult_matrix(t_matrix m1, t_matrix m2);
t_matrix        init_matrix_translation(float x, float y, float z);
t_matrix        init_matrix_identity(void);

/*
**Vector calcul
*/

t_vec           matrix_mult_vector(t_matrix m, t_vec i);
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