/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:08:54 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/29 03:10:44 by saneveu          ###   ########.fr       */
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

t_color			color_helper(int ic1, int ic2, double p)
{
	t_color c;
	t_color c1;
	t_color c2;

	//if (ic1 == ic2)
	//	return (ic1);
	//printf("c1 = %d c2 = %d\n", c1.value, c2.value);
	c1.rgb = fill_rgb(ic1);
	c2.rgb = fill_rgb(ic2);
	c.rgb.r = ft_lerp(c1.rgb.r, c2.rgb.r, p);
	//printf("c1.r = %d || c2.r = %d >> r = %d\n", c1.rgb.r, c2.rgb.r, c.rgb.r);
	c.rgb.g = ft_lerp(c1.rgb.g, c2.rgb.g, p);
	//printf("c1.g = %d || c2.g = %d >> g = %d\n", c1.rgb.g, c2.rgb.g, c.rgb.g);
	c.rgb.b = ft_lerp(c1.rgb.b, c2.rgb.b, p);
	//printf("c1.b = %d || c2.b = %d >> b = %d\n", c1.rgb.b, c2.rgb.b, c.rgb.b);
	c.rgb.a = 0x00;

	c.value = rgb_to_hsv(c.rgb.r, c.rgb.g, c.rgb.b);
	
	//c.value += c.rgb.a;
	return (c);
}

t_color			linear_color(t_env *e, double i, int *p)
{
	double		index;
	double		adjust;
	int			c;

	//if (i <= 0)
	//    index = i / e->iter_max;
//	else
		index = fmod(i, e->cycle - 1) / (e->cycle - 1);
	c = e->div;
	adjust = 0.4;
	index = index * c;
	//adjust = (adjust + 1) - adjust;
	return (color_helper(p[(int)index + 1], p[(int)index], adjust)); 
}

t_color			smooth_color(t_env *e, t_pixel p, int *c)
{
	double 		mult;
	double		nu;
	double		nu_frac;
	double		index;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	index = p.i / e->max_iter * 16;
	return(smooth_color_helper(e, index, nu_frac, c));
}

t_color			smooth_color_helper(t_env *e, double index, double mu, int *c)
{
	t_color		c1;
	t_color 	c2;
	t_color		color;
	int			ic1;
	int			ic2;

	(void)e;
	ic1 = index;
	ic2 = ic1 + 1;
	c1.rgb = fill_rgb(c[ic1]);
	c2.rgb = fill_rgb(c[ic2]);
	color.rgb.r = ft_lerp(c1.rgb.r, c2.rgb.r, mu);
	color.rgb.g = ft_lerp(c1.rgb.g, c2.rgb.g, mu);
	color.rgb.b = ft_lerp(c1.rgb.b, c2.rgb.b, mu);
	color.value = rgb_to_hsv(color.rgb.r, color.rgb.g, color.rgb.b);
	return(color);
}

int			smooth_blue(t_pixel p, int iter_max)
{
	t_color	s;
	double 	nu;
	double	nu_frac;
	double	mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	if (p.i == iter_max)
		return (0x000000);
	nu = (p.i + 2 - log2(log2(sqrt(mult)))) / iter_max;
	nu_frac = nu - (int)nu;
	s.rgb.r = (int)(74 * nu_frac);
	s.rgb.g = (int)(205 * nu_frac);
	s.rgb.b = (int)(196 * nu_frac);
	return (s.rgb.r << 16 | s.rgb.g << 8 | s.rgb.b);
}

int		fire(t_pixel p, int iter_max)
{
	t_color	s;
	double 	nu;
	double	nu_frac;
	double	mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + 3 - log2(log2(sqrt(mult)))) / iter_max;
	nu_frac = nu - (int)nu;
	s.rgb.r = (int)(285 * nu_frac + 70 * nu_frac);
	s.rgb.g = (int)(55 * nu_frac);
	s.rgb.b = (int)(25 * nu_frac);
	return (s.rgb.r << 16 | s.rgb.g << 8 | s.rgb.b);
}