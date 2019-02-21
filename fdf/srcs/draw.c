/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 21:47:16 by saneveu          ###   ########.fr       */
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

void		draw_img(t_env *e)
{
	ft_clear_img(e);
	transform(e);
	print_map_elem(e, e->map);
	do_rectangle(e, e->map);
	print_map_elem(e, e->map);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
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
				ft_line(e, m[i][j].x, m[i][j].y, m[i + 1][j].x, m[i + 1][j].y);
				printf("coord x = %f, y = %f, x2 = %f, y2 = %f \n", m[i][j].x, m[i][j].y, m[i+1][j].x, m[i+1][j].y);
			//	ft_putstr("writing in img\n");
			}
			if (j < e->column - 1)
			{
				ft_line(e, m[i][j].x, m[i][j].y, m[i][j + 1].x, m[i][j + 1].y);
				printf("coord x = %f, y = %f, x2 = %f, y2 = %f \n", m[i][j].x, m[i][j].y, m[i][j+1].x, m[i][j+1].y);
			//	ft_putstr("writing in img\n");
			}
		}
	}
}
