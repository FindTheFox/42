/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:59:31 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/25 13:03:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
    t_env *env;

    if(!(env = (t_env *)malloc(sizeof(t_env))))
        return (0);
    whatfractal(env, av[1], ac);
    whatcolor(env, av[2], ac);
    setup(env);
    do_fractol(env);
    event(env); 
    mlx_loop(env->mlx_ptr);    
    return (0);
}

void    event(t_env *e)
{
    mlx_hook(e->win_ptr, 2, (1L << 0), press_event, e); /*press button*/
    mlx_hook(e->win_ptr, 6, (1<<8), motion_mouse, e); /*change julia set when mouse moving*/
    mlx_hook(e->win_ptr, 17, (1L << 17), ft_exit, e); /*if win close by the cross*/
    mlx_key_hook(e->win_ptr, deal_key, e); /*simple push button*/ 
    mlx_mouse_hook(e->win_ptr, mouse_zoom, e);
    //mlx_loop_hook(e->mlx_ptr, press_event, e);
}