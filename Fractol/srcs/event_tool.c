/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:02:50 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/22 22:01:21 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        zoom(t_env *e, int speed)
{
    e->zoom += speed;
	e->max_iter++;
}

void        change_julia_set(t_env *e)
{
    e->rng == 6 ? e->rng = 0 : e->rng++;
    julias_changes(e);
}

void        move(t_env *e, char c, double m)
{
    if (c == 'x')
        e->offset.x += m;
    else if (c == 'y')
        e->offset.y += m;
	printf("set x = %f\nset y = %f\n", e->offset.x, e->offset.y);
}

void        allow_motion_julia(t_env *e)
{
    !e->motion ? (e->motion = 1) : (e->motion = 0);
}

void        reset(t_env *e)
{
    e->zoom = 200;
    e->offset = (t_index) {.x = 0, .y = 0}; 
}
