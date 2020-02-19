/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:59:44 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 02:59:43 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
static void        vect_parser(t_env *e, char *line)
{
    t_vec v;
    int i;
    int vcount;
    int neg;

    i = -1;
    while (line[++i])
    {
        if (line[i] == '\0' || line[i] == ' ' || line[i] == 'v')
            continue ;
        else
        {
            
        } 
    }
}*/

int         file_parser(t_env *e, char *file)
{
    int fd;
    char *line;

    if (!(fd = open(file, O_RDONLY)))
        return (0);
    e->mesh.size = 0; 
    while (get_next_line(fd, &line))
        ;
    ft_putendl(line);
    return (1);
}

int         main(int ac, char **av)
{
    t_env   env;

    (void)av;
    (void)ac;
    ft_memset(&env, 0, sizeof(t_env));
    /*if (ac == 2)
    {
        if (!(file_parser(&env, av[1])))
            return (0);
    }*/
    init_sdl(&env);
    while (1)
    {
        init_cube(&env);
        cube3d(&env);
        event(&env);
    }
    return (0);
}

