/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:45:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 22:07:38 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	calcul_rotation_x(t_env *e, t_map m)
{
	m.tx = m.rx;
	m.ty = m.ry;
	m.tz = m.rz;
	m.rx = m.tx;
	m.ry = m.ty * cos(e->rotation_x) - m.tz * sin(e->rotation_x);
	m.rz = m.ty * sin(e->rotation_x) + m.tz * cos(e->rotation_x);
	//printf("\nafter rot y = %f", m[i][j].y);
}

void	calcul_rotation_y(t_env *e, t_map m)
{
	m.tx = m.rx;
	m.ty = m.ry;
	m.tz = m.rz;
	m.rx = m.tx * cos(e->rotation_y) + m.tz * sin(e->rotation_y);
	m.ry = m.ty;
	m.rz = m.tx * -sin(e->rotation_y) + m.tz * cos(e->rotation_y);
}

void	calcul_rotation_z(t_env *e, t_map m)
{
	m.tx = m.rx;
	m.ty = m.ry;
	m.tz = m.rz;
	m.rx = m.tx * cos(e->rotation_z) - m.ty * sin(e->rotation_z); 
	m.ry = m.tx * sin(e->rotation_z) + m.ty * cos(e->rotation_z);
	m.rz = m.tz;
}

void		ft_calculate(t_env *e, t_map m, char c)
{
	if (c == 'x')
		calcul_rotation_x(e, m);
	else if (c == 'y')
		calcul_rotation_y(e, m);
	else if (c == 'z')
		calcul_rotation_z(e, m);
}
*/

void		calcul_apply(t_env *e, t_map **map, int i, int j)
{
	float theta;
	float x;
	float y;
	float z;

	x = map[i][j].ox * e->scale;
	y = map[i][j].oy * e->scale;
	z = map[i][j].oz * e->z_height * e->scale;
	//printf("scale x = %f |||| scale y = %f |||| scale z = %f\n", x, y, z);
	//c.color_on == 1 ? set_color(v, &c.map) : 0;
	theta = to_radian(e->rot_y);
	map[i][j].x = x * cos(theta) - z * sin(theta);
	map[i][j].z = z * cos(theta) + x * sin(theta);
	//printf("rot x = %f\n", map.x);
	theta = to_radian(e->rot_x);
	map[i][j].y = y * cos(theta) - z * sin(theta);
	map[i][j].z = z * cos(theta) + y * sin(theta);
	//printf("rot y = %f\n", map.y);
	map[i][j].x += e->move_x;
	map[i][j].y += e->move_y;
	map[i][j].x += e->center_x;
	map[i][j].y += e->center_y;
	//printf("marge x = %f\nmarge y = %f\n", map[i][j].x, map[i][j].y);
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
}
