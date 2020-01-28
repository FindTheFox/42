/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:30:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/28 22:34:58 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		switch_fog(t_wolf *d)
{
	d->fog++;
	if (d->fog == 4)
		d->fog = 0;
}

int			fog(t_wolf *d, Uint32 hexa, float distance)
{
	double		intensity;
	SDL_Color	c;

	if (d->fog == 1)
	{
		c = (SDL_Color){hexa >> 24, hexa >> 16, hexa >> 8, hexa};
		intensity = d->obj_intens / distance;
		if (intensity < 1)
		{
			c.r *= intensity;
			c.g *= intensity;
			c.b *= intensity;
			c.a *= intensity;
			return ((c.r << 24) + (c.g << 16) + (c.b << 8) + (c.a));
		}
	}
	else if (d->fog == 2)
	{
		d->rgb = fill_rgb(hexa);
		intensity = d->obj_intens / distance * 5;
		if (intensity < 1)
		{
			d->rgb.r *= intensity;
			d->rgb.g *= intensity;
			d->rgb.b *= intensity;
		}
		return (rgb_to_hsv(d->rgb.r, d->rgb.g, d->rgb.g));
	}
	else if (d->fog == 3)
		return (light_shade(hexa, distance));
	return (hexa);
}

void			ft_remove_light(Uint8 *component, double delta, int arg)
{
	if (*component > 0)
		*component = (*component * (1 - delta) + ((0x0 >> arg) * delta));
}

Uint32			light_shade(Uint32 hexa, float distance)
{
	SDL_Color	color;
	double		delta;
	
	delta = distance / 3;
	//printf("delta 1 = %f\n", delta);
	delta > 0.9 ? delta = 0.9 : 0;
	//printf("delta 2 = %f\n", delta);
	delta /= 1.50;
	//printf("delta 3 = %f\n", delta);
	hexa |= 0xFF000000;
	color = (SDL_Color){hexa >> 24, hexa >> 16, hexa >> 8, hexa};
	ft_remove_light(&color.r, delta, 24);
	ft_remove_light(&color.g, delta, 16);
	ft_remove_light(&color.b, delta, 8);
	ft_remove_light(&color.a, delta, 0);
	return ((color.r << 24) + (color.g << 16) + (color.b << 8) + (color.a));
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
