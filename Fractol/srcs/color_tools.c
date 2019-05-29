/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:22:13 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/29 18:26:54 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgba		fill_rgb(int c)
{
	t_rgba rgb;
	rgb.r = c / (256 * 256);
	rgb.g = (c/256) %256;
	rgb.b = c%256;
	return(rgb);
}

int				rgb_to_hsv(int r, int g, int b)
{
	return((r * 256 * 256) + (g * 256 ) + b);
}

int			get_color(t_env *e, t_pixel p[WIDTH][HEIGHT], t_index i)
{
	if (p[(int)i.x][(int)i.y].i >= e->max_iter)
		return(0x000000);
	if (e->style_color == 0)
	{
		if (e->smooth == 1)
			return(smooth_color(e, p[(int)i.x][(int)i.y], e->color).value);
		return(linear_color(e, p[(int)i.x][(int)i.y].i, e->color).value);	
	}
	else if (e->style_color == 1)
		return(color_rgb(e, p[(int)i.x][(int)i.y]));
	else if (e->style_color == 2)
		return(color_rgb2(e, p[(int)i.x][(int)i.y]).value);
	else if (e->style_color == 3)
		return(color_gradiant(e, p[(int)i.x][(int)i.y]).value);
	else if (e->style_color == 4)
		return(vasarely(p[(int)i.x][(int)i.y]));
	else if (e->style_color == 5) 
		return(fire(p[(int)i.x][(int)i.y], e->max_iter));
	else if (e->style_color == 6)
		return(zebre_rgb_psyche(e, p[(int)i.x][(int)i.y]).value);
	return(!e->smooth ? (linear_color(e, p[(int)i.x][(int)i.y].i, e->color).value) :
			(smooth_color(e, p[(int)i.x][(int)i.y], e->color).value));
}