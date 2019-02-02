/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/01 23:28:26 by saneveu          ###   ########.fr       */
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

	x = 0;
	while (x < map->column)
	{
		y = 0;
		while (y < map->line)
		{
			ft_line(env, x + env->mx, y + env->my, (x + 1) + env->mx, (y + 1) + env->mx);

		}
	}
}
