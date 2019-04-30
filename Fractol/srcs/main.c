/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:59:31 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/30 03:18:05 by saneveu          ###   ########.fr       */
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
