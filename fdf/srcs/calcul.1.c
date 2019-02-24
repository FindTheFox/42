/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:08:58 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/24 02:36:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double 	    to_radian(double degree)
{
    double radian;

    if (degree == 0)
        return (0);
    radian = degree * (M_PI / 180);
	return (radian);
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
	
	////rotation x check
	
	theta = to_radian(e->rot_x);
	map[i][j].x = x;
	map[i][j].y = y * cos(theta) - z * sin(theta);
	map[i][j].z = y * sin(theta) + z * cos(theta);
	
	////rotation y check
	
	z = map[i][j].z;
	theta = to_radian(e->rot_y);
	map[i][j].x = x * cos(theta) + z * sin(theta);
	map[i][j].z = x * -sin(theta) + z * cos(theta);
	
	////rotation z check
	
	x = map[i][j].x;
	y = map[i][j].y;
	theta = to_radian(e->rot_z);
	map[i][j].x = x * cos(e->rot_z) - y * sin(e->rot_z);
	map[i][j].y = x * sin(e->rot_z) + y * cos(e->rot_z);
	
	////apply modif
	
	map[i][j].x += e->move_x;
	map[i][j].y += e->move_y;
	get_center(e);
	map[i][j].x += e->center_x;
	map[i][j].y += e->center_y;
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
