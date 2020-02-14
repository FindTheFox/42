/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:22:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/14 20:42:42 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    init_data(t_env *e)
{
    e->fNear = 0.1f;
    e->fFar = 1000.0f;
    e->fFov = 90.0f;
    e->fAspectRatio = (float)W_W / (float)W_H;
    e->fFovRad = 1.0f / tanf(e->fFov * 0.5 / 180 * 3.14159f);
    e->vlist.voff_set = (t_vec){ 1,1,0,0 };
}