/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/21 18:54:19 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        draw(t_env *e, t_fractol *f)
{
    f->c_r = f->i.x / e->zoom + e->minx;
    f->c_i = f->i.y / e->zoom + e->miny;
    f->z_r = 0;
    f->z_i = 0;
    f->iter = 0;
    e->choix == 0 ? mandelbrot(f, e): 0;
    e->choix == 1 ? julia(f, e) : 0;
    e->choix == 2 ? lauren(f, e) : 0;
    e->choix == 3 ? burning_ship(f, e) : 0;
    e->choix == 4 ? phoenix(f, e) : 0;
    e->choix == 5 ? tricorn(f, e) : 0;
    e->choix == 6 ? mandelbrot_flower(f, e) : 0;
    e->choix == 7 ? bimandel(f, e) : 0;
    if (e->usr_color == 6)
        color_pixel_img(e, f->i.x, f->i.y, (f->iter <= e->max_iter ? color_rgb(e, f)
        : 0x00000));   
    else
        color_pixel_img(e, f->i.x, f->i.y, (f->iter <= e->max_iter ?
        e->color[f->iter % e->div] : 0x00000));
}

void    *fractol_pixel_wheel(void *thread)
{
    t_fractol   f;
    t_thread    *t;
    t_env       *e;

    e = ((t_thread*)thread)->e;
    t = (t_thread*)thread;
    e->minx = ((e->offset.x + (WIDTH >> 1)) / (e->zoom / 2)) / -2;//((e->x2 - e->x1) * e->zoom);
    e->miny = ((e->offset.y + (HEIGHT >> 1)) / (e->zoom / 2)) / -2;//((e->y2 - e->y1) * e->zoom);
    t->start = t->n * WIDTH / THREADS;
    t->end = (t->n + 1) * WIDTH / THREADS;
    f.i.x = t->start;
    while(f.i.x < t->end)
    {
        f.i.y = -1;
        while(++f.i.y < HEIGHT)
            draw(e, &f);
        f.i.x++; 
    }
    pthread_exit(NULL);
    return (NULL);
}

void        fractol_start(t_env *e)
{
    t_thread    t[THREADS];
    int         i;

    i = 0;
    //fractol_pixel_wheel(e);

    while(i < THREADS)
    {
        t[i].n = i;
        t[i].e = e;
        pthread_create(&(t[i]).id, NULL, fractol_pixel_wheel, &t[i]);
        i++;
    }
    i = -1;
    while(++i < THREADS)
        pthread_join(t[i].id, NULL);
    mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

void        do_fractol(t_env *e)
{
    ft_clear_img(e);
    fractol_start(e);
    //mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

void		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < HEIGHT && x < WIDTH)
		env->img[x + WIDTH * y] = color;
}