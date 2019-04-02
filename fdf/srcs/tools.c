/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/01 16:01:51 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_usage()
{
	ft_putendl("usage : ./fdf [map_file]");
	return (0);
}

void 		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < env->height && x < env->width)
		env->str[x + env->width * y] = color;
}

void		paint_all_in_white(t_env *env)
{
	int x;

	x = 1;
	env->str[x] = 0xffffff;
}

void		display_tab(int **tab, t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < env->line)
	{
		j = 0;
		while (j < env->line)
		{
			ft_putnbr(tab[i][j]);
			ft_putstr(" / \n");
			j++;
		}
		i++;
	}
}

void		reset(t_env *e)
{
	e->rot_x = 0;
	e->rot_y = 0;
	e->rot_z = 0;
	e->move_x = 0;
	e->move_y = 0;
	e->scale = fmin(e->width / 2 / (e->line + e->max_z),
		e->height / 2 / (e->column + e->max_z));
	e->z_height = 0.2;
	draw_img(e);
}

void		ft_clear_img(t_env *e)
{
	int i;

	i = 0;
	while (i < e->width * e->height)
	{
		if (e->str[i] != 0)
			e->str[i] = 0;
		i++;
	}
}

void		display_img(t_env *e)
{
	int i;

	i = 0;
	while (i < e->width * e->height)
	{
		if (e->str[i] != 0)
		{
			ft_putstr("something in str\n");
			return ;
		}
		else
			i++;
	}
	ft_putstr("nothing in str\n");
	return ;
}

int		ft_key_mouse(int key, int x, int y, t_env *env)
{
	t_coord *C1;
	t_coord *C2;

	if (key == 1)
	{
		if (!(C1 = (t_coord *)malloc(sizeof(t_coord))))
			return (0);
		C1->x = x;
		C1->y = y;
	}
	if (key == 2)
	{
		if (!(C2 = (t_coord *)malloc(sizeof(t_coord))))
			return (0);
		C2->x = x;
		C2->y = y;
		//ft_line(env, env->C1->x, env->C1->y, ev->C2->x, env->C2->y);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (0);
}

void		print_map_elem(t_env *env, t_map **map)
{
	int i;
	int j;

	i = -1;
	printf("=============map-elem_start===============\n");
	while (++i < env->line)
	{
		j = -1;
		while (++j < env->column)
			printf("x = %f ||| y = %f\n", map[i][j].x, map[i][j].y);
	}
}

void		choose_color(int z, int z2);