/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 01:00:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/01 00:33:28 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>///
# include "../libft/includes/libft.h"

# define HEIGHT 800
# define WIDTH  1200
# define ZOOM   30

typedef struct  s_rng
{
    double      real;
    double      imag;
}               t_rng;


typedef struct  s_index
{
    int         x;
    int         y;
}               t_index;

typedef struct  s_fractol
{
    double      x;
    double      y;
    double      c_r;
    double      c_i;
    double      z_r;
    double      z_i;
    double      tmp;
    t_rng       j;
}               t_fractol;

typedef struct  s_env
{
    void        *mlx_ptr;
    void        *img_ptr;
    void        *win_ptr;
    int         *img;
    int         bpp;
    int         s_l;
    int         endian;
    double      x_left;
    double      x_right;
    double      y_top;
    double      y_floor;
    double      zoom;
    double      minx;
    double      miny;
    int         max_iter;
    t_index     i;
    int         choix;
    int         rng;
    int         iter;
    int         usr_color;
    int         *color;
    t_rng       julia;
    t_index     offset;
    int         motion;
}               t_env;

int         main(int ac, char **av);
void        fractol(t_env *e);
void		color_pixel_img(t_env *env, int x, int y, int color);
void        setup(t_env *e);
int         do_test(t_fractol *f, t_env *e);
void        do_fractol(t_env *e);

void        draw(t_env *e, t_fractol f);
int         calc_c(t_env *e, int flag);
void        julias_changes(t_env *e);
void        init_fractal(t_env *e);

void        whatfractal(t_env *e, char *name, int ac);
void        whatcolor(t_env *e, char *name, int ac);

void        colorset0(t_env *e);
void        colorset1(t_env *e);
void        colorset2(t_env *e);
void        colorset3(t_env *e);
void        colorset4(t_env *e);

void        mandelbrot(t_fractol f, t_env *e);
void        julia(t_fractol f, t_env *e);
void        lauren(t_fractol f, t_env *e);
void	    phoenix(t_fractol f, t_env *e);

void        event(t_env *e);
void        change_la_couleur(t_env *e);
void        zoom(t_env *e, int speed);
void        change_julia_set(t_env *e);
void        switch_fractal(t_env *e, int c);
void        switch_color(t_env *e);
int         motion_mouse(int x, int y, t_env *e);

int         ft_exit(t_env *e);
void        error();
void		ft_clear_img(t_env *e);

#endif