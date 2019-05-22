/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:20:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/22 22:06:24 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    setup(t_env *e)
{
    e->mlx_ptr = mlx_init();
    e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Fractol");
    e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
    e->img = (int *)mlx_get_data_addr(e->img_ptr, &e->bpp, &e->s_l, &e->endian);
    //e->usr_color = 0;
    e->zoom = 5;
    e->offset = (t_index) {.x = -0.5, .y = 0};
    e->rng = 0;
    e->motion = 0;
    e->julia = (t_rng) {.real = -0.506667, .imag = 0.520000};
    e->x1 = -2.1;
    e->x2 = 0.6;
    e->y1 = -1.2;
    e->y2 = 1.2;
    init_fractal(e);
}

void        julias_changes(t_env *e)
{
	if (!e->rng)
		e->julia = (t_rng) {.real = -0.506667, .imag = 0.520000 };
	else if (e->rng == 1)
		e->julia = (t_rng) {.real = 0.403333, .imag = 0.273333 };
	else if (e->rng == 2)
		e->julia = (t_rng) {.real = 0.386667, .imag = 0.103333 };
	else if (e->rng == 3)
		e->julia = (t_rng) {.real = -0.203333, .imag = -0.696667 };
	else if (e->rng == 4)
		e->julia = (t_rng) {.real = 0.18, .imag = -0.566667 };
	else if (e->rng == 5)
		e->julia = (t_rng) {.real = 0.371504, .imag = -0.153893 };
    else if (e->rng == 6)
        e->julia = (t_rng) {.real = 0.566666, .imag = -0.5};
}

void        init_fractal(t_env *e)
{
    if (e->choix == 0 || e->choix == 3)
    {
        e->zoom = 300;
        e->max_iter = 100;
        e->x1 = -2.1;
        e->x2 = 0.6;
        e->y1 = -1.35;
        e->y2 = 1.2;
    }
    else if (e->choix == 1)
    {
        e->zoom = 300;
        e->max_iter = 300;
        e->x1 = -1.5;
        e->x2 = 1.15;
        e->y1 = -1.15;
        e->y2 = 1.25;
        julias_changes(e);
    }
    else if (e->choix == 6)
    {
        e->max_iter = 50;
        e->zoom = 200;
        e->x1 = -2.5;
        e->x2 = 0.6;
        e->y1 = -2.1;
        e->y2 = 1.2;   
    }
    else if (e->choix == 2)
    {
        e->max_iter = 200;
        e->zoom = 250;
        e->x1 = -3;
        e->x2 = 1;
        e->y1 = -1.5;
        e->y2 = 1.35;
    }
}

void        whatfractal(t_env *e, char *name, int ac)
{
    if (ac >= 2)
    {
        if (!ft_strcmp(name, "Mandelbrot") || ac == 1)
            e->choix = 0;
        else if (!ft_strcmp(name, "Julia"))
            e->choix = 1;
        else
        {
            ft_putendl("Not valids arguments.\n[Mandelbrot - Julia]fractal [1 - 3]colors");
            exit(EXIT_FAILURE);
        }
    }
}

void        whatcolor(t_env *e, char *name, int ac)
{
    if (ac == 3)
    {
        if (ft_atoi(name) == 1)
        {
            e->usr_color = 0;
            colorset0(e);
        }
        else if (ft_atoi(name) == 2)
        {
            e->usr_color = 1;
            colorset1(e);
        }
        else if (ft_atoi(name) == 3)
        {
            e->usr_color = 2;
            colorset2(e);
        }
        else if (ft_atoi(name) == 4)
        {
            e->usr_color = 3;
            colorset2(e);
        }
        else
        {
            ft_putendl("5 colors set available");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        e->usr_color = 0;
        colorset0(e); 
    }
    
}