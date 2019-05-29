/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 01:12:21 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/29 02:29:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        colorset0(t_env *e)
{
    static int color[16] = {
        0xffff7d,
		0xffee7d,
		0xffdf7e,
		0xffcf7e,
		0xffbf7e,
		0xffaf7e,
		0xff9f7e,
		0xff8f7f,
		0xfe7e7f,
		0xee6f7f,
		0xde5e7f,
		0xce4f7f,
		0xbe3f7f,
		0xae2f7f,
		0x9d1f7f,
		0x8d0e7f
	};
	e->div = 16;
	e->color = color;
}

void        colorset3(t_env *e)
{
    static int color[16] = {
        0xf06d89,        
        0xfeaebf,
        0xfbc4d0,
        0xa4ece9,
        0x8fece8,
        0xbeefed,
        0x8fa6ec,
        0xaebeef,
        0xf9cb8a,
        0xf6d19b,
        0xfedfb3,
        0xa39191,
        0xa58d8d,
        0xa17878,
        0xa77070,
    };
	e->div = 16;
    e->color = color;
}

void	colorset1(t_env *e)
{
	static int color[16] = {
		65536 * 66 + 256 * 30 + 15,
		65536 * 25 + 256 * 7 + 26,
		65536 * 9 + 256 * 1 + 47,
		65536 * 4 + 256 * 4 + 73,
		65536 * 0 + 256 * 7 + 100,
		65536 * 12 + 256 * 44 + 138,
		65536 * 24 + 256 * 82 + 177,
		65536 * 57 + 256 * 125 + 209,
		65536 * 134 + 256 * 181 + 229,
		65536 * 211 + 256 * 236 + 248,
		65536 * 241 + 256 * 233 + 191,
		65536 * 248 + 256 * 201 + 95,
		65536 * 255 + 256 * 170 + 0,
		65536 * 204 + 256 * 128 + 0,
		65536 * 153 + 256 * 87 + 0,
		65536 * 106 + 256 * 52 + 3
	};
	e->div = 16;
	e->color = color;
}

void		colorset2(t_env *e)
{
	static int color[16] = {
		0xffffff,
		0xdfffff,
		0xbfffff,
		0xa0ffff,
		0x80ffff,
		0x60dfff,
		0x3fbfff,
		0x1f9fff,
		0x7efe,
		0x5edf,
		0x3fbf,
		0x1fa0,
		0x80,
		0x60,
		0x3f,
		0x1f
	};
	e->div = 16;
	e->color = color;
}

void		colorset4(t_env *e)
{
	static int color[16] = {
		0xb2123e,
		0xab1644,
		0xa41a4b,
		0x9d1e51,
		0x952258,
		0x8e265f,
		0x872b65,
		0x802f6c,
		0x783373,
		0x713779,
		0x6a3b80,
		0x633f86,
		0x5c438d,
		0x544794,
		0x4d4b9a,
		0x464fa1,	
	};
	e->div = 16;
	e->color = color;
}

void		colorset5(t_env *e)
{
	static int color[13] = {
		0x0ee2f5,
		0x0d9df6,
		0x0c58f7,
		0x0b11f7,
		0x4a09f8,
		0x9108f9,
		0xda07fa,
		0xfb06d3,
		0xfc058a,
		0xfd0440,
		0xfd1102,
		0xfe5b01,
		0xffa600,
	};
	e->div = 13;
	e->color = color;
}

int		color_rgb(t_env *e, t_pixel p)
{
	int color;
	int r;
	int g;
	int b;
	double mult;
	double nu;
	double nu_frac;

	color = 0;
	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + 2 - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	r = ft_lerpi(e->r, e->r * p.i, nu_frac);
	g = ft_lerpi(e->g, e->g * p.i, nu_frac);//(int)p.i * (e->g * nu_frac);
	b = ft_lerpi(e->b, e->b * p.i, nu_frac);//(int)p.i * (e->b * nu_frac);
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

t_color		color_rgb2(t_env *e, t_pixel p)
{
	t_color color;
	double	nu;
	double	nu_frac;
	double 	mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	color.rgb.r = (nu_frac * e->r);
	color.rgb.g = (nu_frac * e->g);
	color.rgb.b = (nu_frac * e->b);
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	//printf("color = %d | r = %d | g = %d | b = %d", color.value, e->r, e->g, e->b);
	return (color);
}

t_color		zebre_rgb_psyche(t_env *e, t_pixel p)
{
	t_color color;
	double	nu;
	double	nu_frac;
	double 	mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + 5 - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	color.rgb.r = (e->r / nu_frac);
	color.rgb.g = (e->g / nu_frac);
	color.rgb.b = (e->b / nu_frac);
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	//printf("color = %d | r = %d | g = %d | b = %d", color.value, e->r, e->g, e->b);
	return (color);
}

t_color			color_gradiant(t_env *e, t_pixel p)
{
	t_color	color;
	double	nu;
	double	nu_frac;
	double	mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;	
	color.rgb.r = ft_lerp(e->r, e->r2, nu_frac);
	color.rgb.g = ft_lerp(e->g, e->g2, nu_frac);
	color.rgb.b = ft_lerp(e->b, e->b2, nu_frac);
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	return (color);
}

int			vasarely(t_pixel p)
{
	if (p.c.imag > 0)
		return (0x000000);
	return (0xFFFFFF);
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


