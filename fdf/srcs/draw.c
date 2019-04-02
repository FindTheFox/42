/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/02 17:44:32 by saneveu          ###   ########.fr       */
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
	free(line);
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
			//choose_color(m[i][j].oz);
			if (i < e->line - 1)
				ft_line(e, m[i][j].x, m[i][j].y, m[i + 1][j].x, m[i + 1][j].y, ((t_color *)choose_color(e))->color_1);
			if (j < e->column - 1)
				ft_line(e, m[i][j].x, m[i][j].y, m[i][j + 1].x, m[i][j + 1].y, ((t_color *)choose_color(e))->color_2);
		}
	}
}

t_color			*choose_color(t_env *e)
{
	t_color *c;

	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	e->choice_color == 0 ? (c->color_1 = 0xFFFFFF) && (c->color_2 = 0xFFFFFF) : 0;
	e->choice_color == 1 ? (c->color_1 = 0x00FF00) && (c->color_2 = 0xFF00FF) : 0;
	e->choice_color == 2 ? (c->color_1 = 0xFF0000) && (c->color_2 = 0x36845f) : 0;
	e->choice_color == 3 ? (c->color_1 = 0x490063) && (c->color_2 = 0xe8c9f6) : 0;
	return (c);
}

void		show_commande(t_env*e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0xffffff,
		"(2 & 8) Axe X rotation de : ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 20, 0x00e60000,
		ft_itoa(e->rot_x));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 40, 0xffffff,
		"(4 & 6) Axe Y rotation de : ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 40, 0x00e60000,
		ft_itoa(e->rot_y));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 60, 0xffffff,
		"(7 & 9) Axe z rotation de : ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 60, 0x00e60000,
		ft_itoa(e->rot_z));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 80, 0xffffff,
		"(+ & -) Zoom = ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 180, 80, 0x3225428f,
		ft_itoa(e->scale));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 100, 0xffffff,
		"(Up & Down) z_height = ");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 250, 100, 0x3225428f,
		ft_itoa(e->z_height));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 120, 0xffffff,
		"(R) Reset");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 140, 0xffffff,
		"(I) Iso");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 160, 0xffffff,
		"(P) Para");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 180, 0xffffff,
		"(Arrow) Move");
}

void		draw_img(t_env *e)
{
	ft_clear_img(e);
	transform(e);
	//printf("rot_x = %f // rot_t = %f // rot_z = %f\n", e->rot_x, e->rot_y, e->rot_z);
	do_rectangle(e, e->map);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	show_commande(e);
}
