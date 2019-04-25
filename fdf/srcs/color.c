/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:03:00 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/25 19:19:29 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			choose_color(t_env *e, float z, t_screen *c)
{
	e->choice_color == 0 ? assign_color(c, 0xFFFFFF, 0xFFFFFF) : 0;
	e->choice_color == 1 ? assign_color(c, 0x00FF00, 0xFF80FF) : 0;
	e->choice_color == 2 ? assign_color(c, 0x7ad9dc, 0xff9898) : 0;
	e->choice_color == 3 ? assign_color(c, 0xd40b0b, 0x722b2b) : 0;
	e->choice_color == 4 ? assign_color(c, 0x05ffa1, 0xb967ff) : 0;
	e->choice_color == 5 ? assign_color(c, color_alt(z), color_alt(z)) : 0;
}

void			assign_color(t_screen *c, int color1, int color2)
{
	c->color_1 = color1;
	c->color_2 = color2;
}

int				color_alt(float z)
{
	int color;

	color = 0;
	if (z <= -5)
		color = 0x0b0080;
	else if (z <= 0)
		color = 0x4ec5ff;
	else if (z == 1)
		color = 0xcabc76;
	else if (z > 1 && z <= 10)
		color = 0x7e9e40;
	else if (z > 10 && z <= 20)
		color = 0x718e39;
	else if (z > 20 && z <= 30)
		color = 0x647e33;
	else if (z > 30 && z <= 50)
		color = 0x586e2c;
	else if (z > 50 && z <= 200)
		color = 0xE8EAF6;
	else if (z > 200)
		color = 0xffffff;
	return (color);
}

void			color_event(t_env *e)
{
	if (e->choice_color == 5)
		e->choice_color = 0;
	else
		e->choice_color++;
	draw_img(e);
}

void			free_all(t_env *e)
{
	ft_clear_img(e);
	free(e->s);
	e->s = NULL;
	free_map(e->map, e);
	free(e);
	e = NULL;
}
