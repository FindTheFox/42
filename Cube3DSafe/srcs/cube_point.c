/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:32:25 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 02:37:30 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void        init_cube(t_env *env)
{
    //south
    env->tris[0].p[0] = (t_vec){0.0f, 0.0f, 0.0f};
    env->tris[0].p[1] = (t_vec){0.0f, 1.0f, 0.0f};
    env->tris[0].p[2] = (t_vec){1.0f, 1.0f, 0.0f};

    env->tris[1].p[0] = (t_vec){0.0f, 0.0f, 0.0f};
    env->tris[1].p[1] = (t_vec){1.0f, 1.0f, 0.0f};
    env->tris[1].p[2] = (t_vec){1.0f, 0.0f, 0.0f};

    //east
    env->tris[2].p[0] = (t_vec){1.0f, 0.0f, 0.0f};
    env->tris[2].p[1] = (t_vec){1.0f, 1.0f, 0.0f};
    env->tris[2].p[2] = (t_vec){1.0f, 1.0f, 1.0f};

    env->tris[3].p[0] = (t_vec){1.0f, 0.0f, 0.0f};
    env->tris[3].p[1] = (t_vec){1.0f, 1.0f, 1.0f};
    env->tris[3].p[2] = (t_vec){1.0f, 0.0f, 1.0f};

    //NORTH
    env->tris[4].p[0] = (t_vec){1.0f, 0.0f, 1.0f};
    env->tris[4].p[1] = (t_vec){1.0f, 1.0f, 1.0f};
    env->tris[4].p[2] = (t_vec){0.0f, 1.0f, 1.0f};

    env->tris[5].p[0] = (t_vec){1.0f, 0.0f, 1.0f};
    env->tris[5].p[1] = (t_vec){0.0f, 1.0f, 1.0f};
    env->tris[5].p[2] = (t_vec){0.0f, 0.0f, 1.0f};

    //west
    env->tris[6].p[0] = (t_vec){0.0f, 0.0f, 1.0f};
    env->tris[6].p[1] = (t_vec){0.0f, 1.0f, 1.0f};
    env->tris[6].p[2] = (t_vec){0.0f, 1.0f, 0.0f};

    env->tris[7].p[0] = (t_vec){0.0f, 0.0f, 1.0f};
    env->tris[7].p[1] = (t_vec){0.0f, 1.0f, 0.0f};
    env->tris[7].p[2] = (t_vec){0.0f, 0.0f, 0.0f};

    //top
    env->tris[8].p[0] = (t_vec){0.0f, 1.0f, 0.0f};
    env->tris[8].p[1] = (t_vec){0.0f, 1.0f, 1.0f};
    env->tris[8].p[2] = (t_vec){1.0f, 1.0f, 1.0f};

    env->tris[9].p[0] = (t_vec){0.0f, 1.0f, 0.0f};
    env->tris[9].p[1] = (t_vec){1.0f, 1.0f, 1.0f};
    env->tris[9].p[2] = (t_vec){1.0f, 1.0f, 0.0f};    

    //bottom
    env->tris[10].p[0] = (t_vec){1.0f, 0.0f, 1.0f};
    env->tris[10].p[1] = (t_vec){0.0f, 0.0f, 1.0f};
    env->tris[10].p[2] = (t_vec){0.0f, 0.0f, 0.0f};

    env->tris[11].p[0] = (t_vec){1.0f, 0.0f, 1.0f};
    env->tris[11].p[1] = (t_vec){0.0f, 0.0f, 0.0f};
    env->tris[11].p[2] = (t_vec){1.0f, 0.0f, 0.0f};
}
