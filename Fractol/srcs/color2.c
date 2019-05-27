/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:08:54 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/26 09:06:35 by saneveu          ###   ########.fr       */
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
	c.rgb.r = ft_lerpi((int)c1.rgb.r, (int)c2.rgb.r, p);
	c.rgb.g = ft_lerpi((int)c1.rgb.g, (int)c2.rgb.g, p);
	c.rgb.b = ft_lerpi((int)c1.rgb.b, (int)c2.rgb.b, p);
	c.rgb.a = 0x00;

	c.value = ((c.rgb.r * 256 * 256) + (c.rgb.g * 256 ) + c.rgb.b);
	//c.value += c.rgb.a;
	return (c);
}

t_color			linear_color(t_env *e, double i, int *p)
{
	double		index;
	double		adjust;
	int			c;

	if (e->cycle)
		index = fmod(i, e->cycle - 1) / (e->cycle - 1);
	else
	    index = i / e->iter_max;
	c = e->div - 1;
	adjust = fmod(index, 1.0f / c) * c;
	index = index * c;
	return (color_helper(p[(int)index + 1], p[(int)index], (int)(adjust + 1) - adjust)); 
}
/*
t_color		NOTMYlinear_color(t_env *e, double i, int *p)
{
	double		index;
	double		adjust;
	int			c;

	if (e->cycle)
		index = fmod(i, e->cycle - 1) / (e->cycle - 1);
	else
		index = i / e->iter_max;;
	c = e->div - 1;
	//adjust = fmod(index, 1.0f / c) * c;
	return (color_helper((t_color)(p[(int)(index * c) + 1]),
		(t_color)(p[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}
*/
t_color			smooth_color(t_env *e, t_pixel p, int *c)
{
	double 	index;
	double 	zn;
	double 	nu;
	int		i;
	//double 	adjust;
	
	//**********it = it + 2 - log(log(a² + b²)) / log(2)

	zn = log(p.c.real * p.c.real + p.c.real * p.c.real);
	nu = log(zn) / log(2);
	//i = (int)(sqrt(f->iter + 1 - nu) * (e->div - 1) + 0) % e->di;
	index = p.i + 1 - nu;
	//printf("i = %f\n", i);
	if (index < 0)
	 	index = 0;
	//return(color_helper((t_color)p[i], (t_color)p[i + 1], 0.5));	
	return(color_helper(c[(int)(index)%e->div], c[(int)(index + 1)%e->div], 0.2));
}
