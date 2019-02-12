/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:45:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/12 07:09:44 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_rotation(int key, t_env *e)
{
	if (key == 86 || key == 88)
	{
		e->rotation_x += ft_to_radian(key == 86 ? -(e->speed) : e->speed);
		printf("rota_x = %f\n", e->rotation_x);
	}	
	else if (key == 91 || key == 87)
	{	
		e->rotation_y += ft_to_radian(key == 87 ? -(e->speed) : e->speed);
		printf("rota_y = %f\n", e->rotation_y);
	}
	else if (key == 123)
	{
		e->rotation_z += ft_to_radian(key == 123 ? -(e->speed) : e->speed);
		printf("rota_z = %f\n", e->rotation_z);
	}
}

double 		ft_to_radian(double degree)
{
	return (degree / (180 / M_PI));
}

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

void		ft_transform(t_env *e)
{
	int i;
	int j;

	i = -1;
	tile_apply(e->map, e);
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{	
			ft_calculate(e, e->map[i][j], 'x');
			ft_calculate(e, e->map[i][j], 'y');
			ft_calculate(e, e->map[i][j], 'z');
		}
	}
	marge_apply(e->map, e);
}