/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:08:58 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/11 18:33:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		to_radian(double degree)
{
	double	radian;

	if (degree == 0)
		return (0);
	radian = degree * (M_PI / 180);
	return (radian);
}

void		marge_apply(t_env *e, t_map **m, int i, int j)
{
	m[i][j].x += (float)e->center_width - e->center_x;
	m[i][j].y += (float)e->center_height - e->center_y;
	m[i][j].x += e->move_x;
	m[i][j].y += e->move_y;
}

void		calcul_apply(t_env *e, t_map **map, int i, int j)
{
	float theta;
	float x;
	float y;
	float z;

	x = map[i][j].ox * e->scale;
	y = map[i][j].oy * e->scale;
	z = map[i][j].oz * e->z_height;
	theta = to_radian(e->rot_x);
	map[i][j].x = x;
	map[i][j].y = y * cos(theta) - z * sin(theta);
	map[i][j].z = y * sin(theta) + z * cos(theta);
	z = map[i][j].z;
	theta = to_radian(e->rot_y);
	map[i][j].x = x * cos(theta) + z * sin(theta);
	map[i][j].z = x * -sin(theta) + z * cos(theta);
	x = map[i][j].x;
	y = map[i][j].y;
	theta = to_radian(e->rot_z);
	map[i][j].x = x * cos(theta) - y * sin(theta);
	map[i][j].y = x * sin(theta) + y * cos(theta);
}

void		transform(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
			calcul_apply(e, e->map, i, j);
	}
	e->center_x = e->map[e->line / 2][e->column / 2].x;
	e->center_y = e->map[e->line / 2][e->column / 2].y;
	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
			marge_apply(e, e->map, i, j);
	}
}
