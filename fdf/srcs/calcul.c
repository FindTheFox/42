/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:08:58 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/24 08:37:38 by saneveu          ###   ########.fr       */
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

void		marge_apply(t_env *e, t_map **m, int i, int j)
{
	//if (i == e->line / 2 && j == e->column / 2)
	//	printf("========MILIEU=======");
	//printf("before --> x = %f || y = %f\n", m[i][j].x, m[i][j].y);
	m[i][j].x += (float)e->center_width - e->center_x;
	m[i][j].y += (float)e->center_height - e->center_y;
	//printf("after MARGE --> x = %f || y = %f\n", m[i][j].x, m[i][j].y);
	m[i][j].x += e->move_x;
	m[i][j].y += e->move_y;
	//printf("after MOVE --> x = %f || y = %f\n", m[i][j].x, m[i][j].y);
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
	
	//map[i][j].x += e->move_x;
	//map[i][j].y += e->move_y;
	//get_center(e);
	//apply_center(e, map, i, j);
	//map[i][j].x += e->center_x - e->map[e->line / 2][e->column / 2].x;
	//map[i][j].y += e->center_y - e->map[e->line / 2][e->column / 2].y;
}

void		transform(t_env *e)
{
	int i;
	int j;
	//t_matrix mt;

	/*
	set_matrix(e, &mt);
	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
			mult_perspective(e, e->map, mt, i, j);
	}
	*/

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

void		set_matrix(t_env *e, t_matrix *mt)
{
	//float scale;
	float ar = e->width / e->height;
    float zNear = NEAR;
    float zFar = FAR;
    float zRange = zNear - zFar;
    float tanHalfFOV = tanf(to_radian(FOV / 2.0));

	/*ft_bzero(mt->x, 4);
	ft_bzero(mt->y, 4);
	ft_bzero(mt->z, 4);
	ft_bzero(mt->w, 4);
	mt->x[0] = scale; // scale the x coordinates of the projected point
	mt->y[1] = scale; // scale the y coordinates of the projected point
	mt->y[2] = -FAR / (FAR - NEAR); // used to remap z to [0,1]
	mt->w[2] = -FAR * NEAR / (FAR - NEAR); // used to remap z [0,1]
	mt->z[3] = -1; // set w = -z
	mt->w[3] = 0;*/
	mt->x[0] = 1.0f / (tanHalfFOV * ar);
    mt->x[1] = 0.0f;
    mt->x[2] = 0.0f;
    mt->x[3] = 0.0f;

    mt->y[0] = 0.0f;
    mt->y[1] = 1.0f / tanHalfFOV;
    mt->y[2] = 0.0f;
    mt->y[3] = 0.0f;

    mt->z[0] = 0.0f;
    mt->z[1] = 0.0f;
    mt->z[2] = (-zNear - zFar) / zRange;
    mt->z[3] = 2.0f * zFar * zNear / zRange;

    mt->w[0] = 0.0f;
    mt->w[1] = 0.0f;
    mt->w[2] = 1.0f;
    mt->w[3] = 0.0f;
}

void		mult_perspective(t_env *e, t_map **m, t_matrix mt, int i, int j)
{
	float x;
	float y;
	float z;
	float w;

	(void)e;
	x = m[i][j].ox;// * e->scale;
	y = m[i][j].oy;// * e->scale;
	z = m[i][j].oz;// * e->z_height;
	//printf("before --> x = %f  //  y = %f  //  z = %f\n", x, y, z);
	m[i][j].x = x * mt.x[0] + y * mt.y[0] + z * mt.z[0] + mt.w[0];
	m[i][j].y = x * mt.x[1] + y * mt.y[1] + z * mt.z[1] + mt.w[1];
	m[i][j].z = x * mt.x[2] + y * mt.y[2] + z * mt.z[2] + mt.w[2];
	w = x * mt.x[2] + y * mt.y[2] + z * mt.z[3] + mt.w[3];
	//printf("After --> x = %f  //  y = %f  //  z = %f\n", m[i][j].x, m[i][j].y, m[i][j].z);
	if (w != 1)
	{
		x /= w;
		y /= w;
		z /= w;
	}
	m[i][j].x = x;
	m[i][j].y = y;
	m[i][j].z = z;
} 
