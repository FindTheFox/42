/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:03:00 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/12 17:24:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color			*choose_color(t_env *e, float z)
{
	t_color *c;

	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	e->choice_color == 0 ? assign_color(c, 0xFFFFFF, 0xFFFFFF) : 0;
	e->choice_color == 1 ? assign_color(c, 0x00FF00, 0xFF80FF) : 0;
	e->choice_color == 2 ? assign_color(c, 0xFF2010, 0x36855d) : 0;
	e->choice_color == 3 ? assign_color(c, 0x490063, 0xe8c9f6) : 0;
	e->choice_color == 4 ? assign_color(c, color_alt(z), color_alt(z)) : 0;
	return (c);
}

void			assign_color(t_color *c, int color1, int color2)
{
	c->color_1 = color1;
	c->color_2 = color2;
}

int				color_alt(float z)
{
	int color;

	color = 0;
	if (z <= 0)
		color = 0x00B8D4;
	else if (z == 1)
		color = 0x795548;
	else if (z >= 2 && z <= 9)
		color = 0x558B2F;
	else if (z > 9 && z <= 35)
		color = 0x33691E;
	else if (z > 35)
		color = 0xE8EAF6;
	return (color);
}
