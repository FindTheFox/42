/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 01:00:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/25 05:11:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>///
# include "../libft/includes/libft.h"

# define HEIGHT 800
# define WITDH 1200

typedef struct  s_fractol
{
    double   x;
    double   y;
    double   c_r;
    double   c_i;
    double   z_r;
    double   z_i;
    int     iter;
    double   tmp;
}               t_fractol;

typedef struct  s_index
{
    int         x;
    int         y;
}               t_index;

typedef struct  s_env
{
    void    *mlx_ptr;
    void    *img_ptr;
    void    *win_ptr;
    int     *img;
    int     bpp;
    int     s_l;
    int     endian;
    double   x_left;
    double   x_right;
    double   y_top;
    double   y_floor;
    double   zoom;
    double   scalex;
    double  scaley;
    int     max_iter;
    t_index i;
}               t_env;

int         main(int ac, char **av);
void        fractol(t_env *e);
void		color_pixel_img(t_env *env, int x, int y, int color);
void        setup(t_env *e);
int         do_test(t_fractol *f, t_env *e);
void        draw_fractol(t_env *e, t_fractol f);
int         mandelbrot(t_fractol f, t_env *e);

#endif