/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/18 17:08:59 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line(t_env *env, t_screen *s, int color)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs((int)s->x2 - (int)s->x1) >= ft_abs((int)s->y2 - (int)s->y1))
		line->lenght = ft_abs((int)s->x2 - (int)s->x1);
	else
		line->lenght = ft_abs((int)s->y2 - (int)s->y1);
	line->dx = (s->x2 - s->x1) / line->lenght;
	line->dy = (s->y2 - s->y1) / line->lenght;
	line->x = s->x1 + 0.5;
	line->y = s->y1 + 0.5;
	line->i = 1;
	while (line->i <= line->lenght
	&& line->x < env->width && line->y < env->height)
	{
		color_pixel_img(env, (int)line->x, (int)line->y, color);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}

void		do_rectangle(t_env *e, t_map **m)
{
	int			i;
	int			j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			choose_color(e, m[i][j].oz, e->s);
			if (i < e->line - 1)
			{
				coord(e->s, m[i][j].x, m[i][j].y, m[i + 1][j].x, m[i + 1][j].y);
				ft_line(e, e->s, e->s->color_1);
			}
			if (j < e->column - 1)
			{
				coord(e->s, m[i][j].x, m[i][j].y, m[i][j + 1].x, m[i][j + 1].y);
				ft_line(e, e->s, e->s->color_2);
			}
		}
	}
}

void		coord(t_screen *s, int x1, int y1, int x2, int y2)
{
	s->x1 = x1;
	s->y1 = y1;
	s->x2 = x2;
	s->y2 = y2;
}

void		draw_img(t_env *e)
{
	ft_clear_img(e);
	transform(e);
	do_rectangle(e, e->map);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	show_commande(e);
}
