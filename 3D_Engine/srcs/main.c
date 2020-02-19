/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:59:44 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/19 20:24:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/3d_engine.h"

static void     framerate(t_env *e)
{
    float           oldtime;

    oldtime = e->time;
    e->time = SDL_GetTicks();
    e->theta = (e->time - oldtime) / 1000;
}

int         main(int ac, char **av)
{
    t_env   env;
    int     i;
    int     mi;
    
    ft_memset(&env, 0, sizeof(t_env));
    if (ac >= 2)
    {
        env.nbmesh = ac - 1;
        if (!(env.mesh = (t_mesh *)malloc(sizeof(t_mesh) * env.nbmesh)))
            ft_exit(&env, "Mesh Alloc Error", 0); 
        i = 1;
        mi = 0;
        while (i < ac)
        {
            file_parser(&env, av[i], mi);
            mi++;
            i++;
        }
    }
    init_sdl(&env);
    init_data(&env);
    while (1)
    {
        framerate(&env);
        engine_3d(&env);
        event(&env);
    }
    return (0);
}

