/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:03:00 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/10 17:03:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			choose_color(t_env *e, float z, t_color *c)
{
	e->choice_color == 0 ? (c->color_1 = 0xFFFFFF) && (c->color_2 = 0xFFFFFF) : 0;
	e->choice_color == 1 ? (c->color_1 = 0x00FF00) && (c->color_2 = 0xFF00FF) : 0;
	e->choice_color == 2 ? (c->color_1 = 0xFF0000) && (c->color_2 = 0x36845f) : 0;
	e->choice_color == 3 ? (c->color_1 = 0x490063) && (c->color_2 = 0xe8c9f6) : 0;
	e->choice_color == 4 ? (c->color_1 = color_alt(z)) && (c->color_2 = color_alt(z)) : 0;
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