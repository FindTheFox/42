/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/11 03:16:42 by saneveu          ###   ########.fr       */
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

void		print_map_elem(t_env *env, t_map **map)
{
	int i;
	int j;

	i = -1;
	while (++i < env->line)
	{
		j = - 1;
		while (++j < env->column)
		{
			ft_putstr("/ x = ");
			ft_putnbr(map[i][j].x);
			ft_putstr("/ y = ");
			ft_putnbr(map[i][j].y);
			ft_putstr("/ z = ");
			ft_putnbr(map[i][j].z);
		}
	}
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
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}
