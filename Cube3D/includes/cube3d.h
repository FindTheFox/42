/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:57:46 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 03:25:49 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../SDL/SDL.h"
# include "../libft/includes/libft.h"

# define W_W 800
# define W_H 800

typedef struct      s_vec
{
    float   x;
    float   y;
    float   z;
}                   t_vec;

typedef struct      s_triangle
{
    t_vec   p[3];
}                   t_triangle;

typedef struct      s_mesh
{
    t_triangle      tris[12];
}                   t_mesh;

typedef struct      s_matrix
{
    float           m[4][4];
}                   t_matrix;

typedef struct      s_env
{
    float           fps;
    float           time;
    float           frametime;
    t_vec           vcamera;
    t_matrix        matproj;
    t_matrix        matrotz;
    t_matrix        matrotx;
    t_matrix        matroty;
    t_triangle      tris[12];
    t_mesh          mesh;
    SDL_Window      *window;
    SDL_Event       event;
    SDL_Renderer    *rend;
    SDL_Texture     *screen;
    SDL_Surface     *winsurf;
}                   t_env;

void        ft_exit(t_env *env, char *s, int flag);
void        init_cube(t_env *env);
void        init_sdl(t_env *env);

void        matrix_mult_vect(t_vec *i, t_vec *o, t_matrix *m);
void        init_matrix(t_env *e);
void        init_matrix_rotx(t_env *e, float theta);
void        init_matrix_rotz(t_env *e, float theta);

void        draw_triangle(t_env *e, t_vec p[3]);

void        event(t_env *env);

void        back_to_env(t_env *e, t_vec vec[3], int i);

#endif