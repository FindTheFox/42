/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:30:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/16 19:18:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		switch_fog(t_wolf *d)
{
	if (d->fog == 0)
		d->fog = 1;
	else
		d->fog = 0;
}

int			fog(t_wolf *d, t_rgba rgb, int flag)
{
	double intensity;

	if (flag == 0)
		intensity = d->obj_intens / d->ray.perpwalldist * 5;
	else
		intensity = d->obj_intens / d->ray.distcurrent * 5;
	if (intensity <= 1 && d->fog)
	{
		rgb.r *= intensity;
		rgb.g *= intensity;
		rgb.b *= intensity;
	}
	return (rgb_to_hsv(rgb.r, rgb.g, rgb.b));
}

t_rgba		fill_rgb(int c)
{
	t_rgba rgb;

	rgb.r = c / (256 * 256);
	rgb.g = (c / 256) % 256;
	rgb.b = c % 256;
	return (rgb);
}

int			rgb_to_hsv(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
