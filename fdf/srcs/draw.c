/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/11 08:21:04 by saneveu          ###   ########.fr       */
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

void		calcul_pos_iso(t_map **m, int i, int j, t_env *e)
{
	(void)e;
	m[i][j].cx = (m[i][j].rx - m[i][j].ry);//mx
	m[i][j].cy = -(m[i][j].rz) + m[i][j].rx + m[i][j].ry + e->my;//my
}

void		calcul_pos_para(t_map **m, int i, int j, t_env *e);

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
			m[i][j].rx = m[i][j].x * e->x_unit + e->mx;//mx
			m[i][j].ry = m[i][j].y * e->y_unit + e->my;//my
			m[i][j].rz = m[i][j].z;
		}
	}
}

void		do_rectangle(t_env *e, t_map **m)
{
	int i;
	int j;

	tile_apply(m, e);
	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			if (i < e->line - 1)
				ft_line(e, m[i][j].rx, m[i][j].ry, m[i + 1][j].rx, m[i + 1][j].ry);
			if (j < e->column - 1)
				ft_line(e, m[i][j].rx, m[i][j].ry, m[i][j + 1].rx, m[i][j + 1].ry);
		}
	}
}
