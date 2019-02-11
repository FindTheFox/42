/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:45:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/11 08:32:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_rotation(int key, t_env *e)
{
	if (key == 86 || key == 88)
	{
		e->rotation_x += ft_to_radian(key == 86 ? -(e->speed) : e->speed);
		ft_rotation_x(e, e->map);
	}
	else if (key == 91 || key == 87)
	{
		e->rotation_y += ft_to_radian(key == 87 ? -(e->speed) : e->speed);
		ft_rotation_y(e, e->map);
	}
	else if (key == 123)
	{
		e->rotation_z += ft_to_radian(key == 123 ? -(e->speed) : e->speed);
		ft_rotation_z(e, e->map);
	}
}

double 		ft_to_radian(double degree)
{
	return (degree / (180 / M_PI));
}


void	ft_rotation_x(t_env *e, t_map **m)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].rx = m[i][j].x;	
			m[i][j].rx = m[i][j].y;	
			m[i][j].rx = m[i][j].z;	
			m[i][j].x = m[i][j].rx;
			m[i][j].y = m[i][j].ry * cos(e->rotation_x) - m[i][j].rz * sin(e->rotation_x);
			m[i][j].z = m[i][j].ry * sin(e->rotation_x) + m[i][j].rz * cos(e->rotation_x);
		}
	}
}

void	ft_rotation_y(t_env *e, t_map **m)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].x = m[i][j].rx * cos(e->rotation_y) + m[i][j].rz * sin(e->rotation_y);
			m[i][j].y = m[i][j].ry;
			m[i][j].z = m[i][j].rx * -sin(e->rotation_y) + m[i][j].rz * cos(e->rotation_y);
		}
	}
}

void	ft_rotation_z(t_env *e, t_map **m)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].x = m[i][j].rx * cos(e->rotation_z) - m[i][j].ry * sin(e->rotation_z); 
			m[i][j].y = m[i][j].rx * sin(e->rotation_z) + m[i][j].ry * cos(e->rotation_z);
			m[i][j].z = m[i][j].rz;
		}
	}
}