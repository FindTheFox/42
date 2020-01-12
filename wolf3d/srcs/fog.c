/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:30:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/12 21:01:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void        switch_fog(t_wolf *d)
{
    if (d->fog == 0)
        d->fog = 1;
    else
        d->fog = 0;
}

int             fog(t_wolf *d, t_rgba rgb, int flag)
{
    double intensity;

    if (flag == 0)
        intensity = d->obj_intens / d->ray.perpwalldist * 10;
    else
        intensity = d->obj_intens / d->ray.distcurrent * 10;
    if (intensity <= 1 && d->fog)
    {
        rgb.r *= intensity;
        rgb.g *= intensity;
        rgb.b *= intensity;
    }
    return (rgb_to_hsv(rgb.r, rgb.g, rgb.b));
}