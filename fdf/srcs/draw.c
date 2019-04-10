/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/10 17:03:40 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *env, float x1, float y1, float x2, float y2, int color)
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
		color_pixel_img(env, (int)line->x, (int)line->y, color); //nice cyan (0x36845f) // fonction choix de couleurs
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	//printf("t_line addr = %p\n", line);
	free(line);
}

void		do_rectangle(t_env *e, t_map **m)
{
	int i;
	int j;
	t_color *c;

	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return ;
	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			choose_color(e, m[i][j].oz, c);
			if (i < e->line - 1)
				ft_line(e, m[i][j].x, m[i][j].y, m[i + 1][j].x, m[i + 1][j].y, c->color_1);
			if (j < e->column - 1)
				ft_line(e, m[i][j].x, m[i][j].y, m[i][j + 1].x, m[i][j + 1].y, c->color_2);
		}
	}
	free(c);
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
