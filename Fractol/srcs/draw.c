/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/12 20:59:59 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        draw(t_env *e, t_fractol *f)
{
    f->c_r = e->i.x / e->zoom + e->minx;
    f->c_i = e->i.y / e->zoom + e->miny;
    f->z_r = 0;
    f->z_i = 0;
    e->iter = 0;
    if (e->choix == 0)
        mandelbrot(*f, e);
    else if (e->choix == 1)
        julia(*f, e);
    else if (e->choix == 2)
        lauren(*f, e);
    else if (e->choix == 3)
        phoenix(*f, e);
    else if (e->choix == 4)
        burning_ship(*f, e);
    else if (e->choix == 5)
        tricorn(*f, e);
    if (e->usr_color == 6)
        color_pixel_img(e, e->i.x, e->i.y, (e->iter <= e->max_iter ? color_rgb(e)
        : 0x00000));   
    else
        color_pixel_img(e, e->i.x, e->i.y, (e->iter <= e->max_iter ?
        e->color[e->iter % e->div] : 0x00000));
}

void    *fractol_pixel_wheel(void *thread)
{
    t_fractol   f;
    t_thread    *t;
    t_env       *e;
    int         max;

    e = (t_env *)((t_thread *)thread)->e;
    t = (t_thread *)thread;
    e->minx = ((e->offset.x + (WIDTH >> 1)) / (e->zoom / 2)) / -2;//
    e->miny = ((e->offset.y + (HEIGHT >> 1)) / (e->zoom / 2)) / -2;//
    e->i.y = t->n * HEIGHT / THREADS;
    max = (t->n + 1) * HEIGHT / THREADS;
    while(e->i.y < max)
    {
        e->i.x = -1;
        while(++e->i.x < WIDTH)
            draw(e, &f);
        e->i.y++;
    }
    pthread_exit(NULL);
    return (NULL);
}

void        fractol_start(t_env *e)
{
    t_thread    t[THREADS];
    int         i;

    i = 0;
    while(i < THREADS)
    {
        t[i].n = i;
        t[i].e = e;
        if (pthread_create(&(t[i].id), NULL, fractol_pixel_wheel, (void *)&t[i]))
        {
            printf("echec creation thread %d\n", t[i].n);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while(i < THREADS)
        pthread_join(t[i++].id, NULL);
}

void        do_fractol(t_env *e)
{
    ft_clear_img(e);
    fractol_start(e);
    mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}

void		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < HEIGHT && x < WIDTH)
		env->img[x + WIDTH * y] = color;
}