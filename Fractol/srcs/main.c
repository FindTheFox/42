/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:59:31 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/09 07:07:37 by saneveu          ###   ########.fr       */
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
    mlx_key_hook(env->win_ptr, deal_key, env); /*simple push button*/
    mlx_hook(env->win_ptr, 0, (1<<8), motion_mouse, env); /*change julia set when mouse moving*/
    mlx_hook(env->win_ptr, 17, (1L << 17), ft_exit, env); /*if win close by the cross*/
    mlx_mouse_hook(env->win_ptr, mouse_zoom, env);
    mlx_loop(env->mlx_ptr);
    return (0);
}
