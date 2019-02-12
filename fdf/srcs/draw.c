/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/12 07:07:50 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *env, float x1, float y1, float x2, float y2)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs((int)x2 - (int)x1) >= ft_abs((int)y2 - (int)y1))
		line->lenght = ft_abs((int)x2 - (int)x1);
	else
		line->lenght = ft_abs((int)y2 - (int)y1);
	line->dx = (x2 - x1) / line->lenght;
	line->dy = (y2 - y1) / line->lenght;
	line->x = x1 + 0.5;
	line->y = y1 + 0.5;
	line->i = 1;
	while (line->i <= line->lenght && line->x < env->width && line->y < env->height)
	{
		color_pixel_img(env, (int)line->x, (int)line->y, 0xffffff);
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, line->x, line->y, 0xffffff);
		//env->img_str[((int)line->y * env->width) + (int)line->x] = 0xffffff;
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}

	free(line);
}

void		tile_apply(t_map **m, t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].rx = m[i][j].x * e->x_unit;
			m[i][j].ry = m[i][j].y * e->y_unit;
			//m[i][j].rz = m[i][j].z * e->z_unit + 1;
		}
	}
}

void		marge_apply(t_map **m, t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].fx = round(m[i][j].rx + e->mx);
			m[i][j].fy = round(m[i][j].ry + e->my);
		}
	}
}

void		ft_draw(t_env *e)
{
	tile_apply(e->map, e);
	ft_transform(e);
	marge_apply(e->map, e);
	do_rectangle(e, e->map);
}

void		do_rectangle(t_env *e, t_map **m)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			if (i < e->line - 1)
			{
				ft_line(e, m[i][j].fx, m[i][j].fy, m[i + 1][j].fx, m[i + 1][j].fy);
			//	printf("coord x = %f, y = %f, x2 = %f, y2 = %f \n", m[i][j].fx, m[i][j].fy, m[i+1][j].fx, m[i+1][j].fy);
			//	ft_putstr("writing in img\n");
			}
			if (j < e->column - 1)
			{
				ft_line(e, m[i][j].fx, m[i][j].fy, m[i][j + 1].fx, m[i][j + 1].fy);
			//	printf("coord x = %f, y = %f, x2 = %f, y2 = %f \n", m[i][j].fx, m[i][j].fy, m[i][j+1].fx, m[i][j+1].fy);
			//	ft_putstr("writing in img\n");
			}
		}
	}
}
