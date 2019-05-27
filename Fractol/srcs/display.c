/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:13:49 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/26 07:13:59 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    display(t_env *e)
{
    void    *m;
    char    *c;

    m = e->mlx_ptr;
    thread_start(e, backscreen);
    mlx_put_image_to_window(e->mlx_ptr, e->d->win, e->d->img, 0, 0);
    mlx_string_put(m, e->d->win, 10, 10, 0xFF0000, "*******Keys*******");
    mlx_string_put(m, e->d->win, 15, 30, 0x000000, "PAD NUM : Fractal choice");
    mlx_string_put(m, e->d->win, 15, 50, 0x000000, "1 -> 6 : Colors");
    mlx_string_put(m, e->d->win, 15, 70, 0x000000, "Arrows : Move");
    mlx_string_put(m, e->d->win, 15, 90, 0x000000, "+ & - : Cycle Color");
    mlx_string_put(m, e->d->win, 15, 110, 0x000000, "[Julia] J : change julia set const");
    mlx_string_put(m, e->d->win, 15, 130, 0x000000, "[Julia] Space : Allow mouse motion");
    mlx_string_put(m, e->d->win, 10, 160, 0x000fff, "*******Current params*******");
    mlx_string_put(m, e->d->win, 15, 180, 0x000000, "Color =");
    c = ft_itoa(e->usr_color);
    mlx_string_put(m, e->d->win, 100, 180, 0x000000, c);
    mlx_string_put(m, e->d->win, 15, 200, 0x00ffff, "Zoom =");
    c = ft_itoa(e->zoom);
    mlx_string_put(m, e->d->win, 100, 200, 0x00ffff, c);
    mlx_string_put(m, e->d->win, 15, 220, 0xffffff, "Max iter =");
    c = ft_itoa(e->max_iter);
    mlx_string_put(m, e->d->win, 100, 220, 0xffff00, c);
    free(c);  
}

void    *backscreen(void *thread)
{
    t_index     i;
    t_thread    *t;
    t_env       *e;
    
    e = ((t_thread*)thread)->e;
    t = (t_thread *)thread; 
    t->start = t->n * 400 / THREADS;
    t->end = (t->n + 1) * 400 / THREADS;
    i.x = t->start;
    if (e->usr_color == 6)
    {
        while (i.x < t->end)
        {
            i.y = -1;
            while (++i.y < 400)
                color_pixel_img(e->d->tab, i, e->d->size, 0x2c5699);
            i.x++;
        }
    }
    else
    {
        while (i.x < t->end)
        {
            i.y = -1;
            while (++i.y < 400)
                color_pixel_img(e->d->tab, i, e->d->size, e->color[(int)(i.x * e->d->size.x/3 + i.y) % e->div]);
            i.x++;
        }
    }
    pthread_exit(NULL);
    return (NULL);
}

void    init_second_win(t_env *e)
{
    e->d->size = (t_index) {.x = 400, .y = 400};
    e->d->win = mlx_new_window(e->mlx_ptr, e->d->size.x, e->d->size.y, "Assistant");
    e->d->img = mlx_new_image(e->mlx_ptr, e->d->size.x, e->d->size.y);
    e->d->tab = (int*)mlx_get_data_addr(e->d->img, &e->d->bpp, &e->d->s_l, &e->d->endian);
    e->d->i = 1;
}

void    help_event(t_env *e)
{
    e->help == 0 ? e->help = 1 : (e->help = 0);
    if (e->help == 1)
    {
        if (!(e->d = (t_dis *)malloc(sizeof(t_dis))))
            return ;
        init_second_win(e);
        display(e);
    }
    else if (e->help == 0)
    {
        mlx_destroy_image(e->mlx_ptr, e->d->img);
        mlx_destroy_window(e->mlx_ptr, e->d->win);
    }

}