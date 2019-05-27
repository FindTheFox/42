/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/27 22:47:24 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        draw_pixel(t_env *e)
{
    t_index i;
    
    i.x = -1;
    while (++i.x < WIDTH)
    {
        i.y = -1;
        while (++i.y < HEIGHT)
        {
            color_pixel_img(e->img, i, e->size, get_color(e, e->data, i));
        }
    }
}

void        draw(t_env *e, t_fractol *f)
{
    f->c_r = (f->i.x / e->zoom) + e->x1 + e->offset.x;//(f->i.x * (e->x2 - e->x1) / WIDTH + e->x1);//
    f->c_i = (f->i.y / e->zoom) + e->y1 + e->offset.y;//(f->i.y * (e->y2 - e->y1) / HEIGHT + e->y1);//
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
    //color_pixel_img(e->img, f->i, e->size, get_color(e, f));
}

void    *fractol_pixel_wheel(void *thread)
{
    t_fractol   f;
    t_thread    *t;
    t_env       *e;

    e = ((t_thread*)thread)->e;
    e->f = &f;
    t = (t_thread*)thread;
    t->start = t->n * WIDTH / THREADS;
    t->end = (t->n + 1) * WIDTH / THREADS;
    f.i.x = t->start;
    while(f.i.x < t->end)
    {
        f.i.y = -1;
        while(++f.i.y < HEIGHT)
        {
            draw(e, &f);
            e->data[(int)f.i.x][(int)f.i.y] = (t_pixel){.c.real = f.z_r, .c.imag = f.z_i,
             .i = f.iter};
        }
        f.i.x++; 
    }
    pthread_exit(NULL);
    return (NULL);
}

void        thread_start(t_env *e, void *f(void *))
{
    t_thread    t[THREADS];
    int         i;

    i = 0;
    while(i < THREADS)
    {
        t[i].n = i;
        t[i].e = e;
        pthread_create(&(t[i]).id, NULL, f, &t[i]);
        i++;
    }
    i = -1;
    while(++i < THREADS)
        pthread_join(t[i].id, NULL);
}

void        do_fractol(t_env *e)
{
    ft_clear_img(e);
    thread_start(e, fractol_pixel_wheel);
    draw_pixel(e);
    mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
    if (e->help == 1)
        display(e);
}

void		color_pixel_img(int *img, t_index i, t_index size, int color)
{
	if (i.x >= 0 && i.y >= 0 && i.y < size.y && i.x < size.x)
        img[(int)(i.x + size.x * i.y)] = color;
}