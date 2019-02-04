/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/04 19:48:50 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_display_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->column)
		{
			ft_putnbr(map->tab[i][j]);
			ft_putchar('|');
			j++;
		}
		i++;
	}
}

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

void		ft_draw(t_map *map, t_env *env)
{
	int x;
	int y;

	if(!(env->C1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if(!(env->C2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	x = 0;
	while (x < map->line)
	{
		y = 0;
		while (y < map->column)
		{
			ft_iso(env, map, x, y);
			y++;
		}
		x++;
	}
}

void	ft_iso(t_env *mlx, t_map *map, int i, int j)
{
	mlx->C1->x = (j - i) * mlx->x_unit;
	mlx->C1->y = (j + i) * mlx->y_unit + mlx->z_unit * map->tab[i][j];
	//mlx->C1->color = ft_choose_color(map->tab[i][j], mlx);
	if (i < map->line - 1)
	{
		mlx->C2->x = (j - i - 1) * mlx->x_unit;
		mlx->C2->y = (j + i + 1) * mlx->y_unit + mlx->z_unit * map->tab[i + 1][j];
		//mlx->C2->color = ft_choose_color(map->tab[i + 1][j], mlx);
		ft_line(mlx, mlx->C1->x, mlx->C1->y, mlx->C2->x, mlx->C2->y);
	}
	if (j < map->column - 1)
	{
		mlx->C2->x = (j + 1 - i) * mlx->x_unit;
		mlx->C2->y = (j + 1 + i) * mlx->y_unit + mlx->z_unit * map->tab[i][j + 1];
		//mlx->C2->color = ft_choose_color(map->tab[i][j + 1], mlx);
		ft_line(mlx, mlx->C1->x, mlx->C1->y, mlx->C2->x, mlx->C2->y);
	}
}