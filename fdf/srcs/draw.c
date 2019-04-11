/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/11 19:00:33 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *env, t_screen *s, int color)
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
	while (line->i <= line->lenght && line->x < env->width && line->y < env->height)
	{
		color_pixel_img(env, (int)line->x, (int)line->y, color);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(s);
	free(line);
}

void		do_rectangle(t_env *e, t_map **m)
{
	int i;
	int j;
	t_color *c;
	t_screen *s1;
	t_screen *s2;

	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return ;
	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			s1 = assign_coord(m[i][j].x, m[i][j].y, m[i+1][j].x, m[i+1][j].y);
			s2 = assign_coord(m[i][j].x, m[i][j].y, m[i][j+1].x, m[i][j+1].y);
			choose_color(e, m[i][j].oz, c);
			if (i < e->line - 1)
				ft_line(e, s1, c->color_1);
			if (j < e->column - 1)
				ft_line(e, s2, c->color_2);
		}
	}
	free(c);
}

t_screen	*assign_coord(int x1, int y1, int x2, int y2)
{
	t_screen *s;

	if (!(s = (t_screen *)malloc(sizeof(t_screen))))
		return (NULL);
	s->x1 = x1;
	s->y1 = y1;
	s->x2 = x2;
	s->y2 = y2;
	return (s);
}

void		show_commande(t_env*e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0xffffff,
		"(2 & 8) Axe X rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 20, 0x00e60000,
		ft_itoa(e->rot_x));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 40, 0xffffff,
		"(4 & 6) Axe Y rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 40, 0x00e60000,
		ft_itoa(e->rot_y));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 60, 0xffffff,
		"(7 & 9) Axe z rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 60, 0x00e60000,
		ft_itoa(e->rot_z));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 80, 0xffffff,
		"(+ & -) Zoom =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 180, 80, 0x3225428f,
		ft_itoa(e->scale));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 100, 0xffffff,
		"(Up & Down) z_height =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 250, 100, 0x3225428f,
		ft_itoa(e->z_height));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 120, 0xffffff,
		"(C) Color =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 140, 120, 0x3225428f,
		ft_itoa(e->choice_color));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 140, 0xffffff,
		"(R) Reset");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 160, 0xffffff,
		"(I) Iso");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 180, 0xffffff,
		"(P) Para");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 200, 0xffffff,
		"(Arrow) Move");
}

void		draw_img(t_env *e)
{
	ft_clear_img(e);
	transform(e);
	do_rectangle(e, e->map);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	show_commande(e);
}
