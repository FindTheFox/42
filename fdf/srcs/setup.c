/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:48:27 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/10 08:03:03 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		 setup_img(t_env *env)
{
	int		bpp;
	int		s_l;
	int		endian;

	env->img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->str = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &s_l, &endian);
}

t_env		*setup_mlx(t_env *env)
{

	env->height = HEIGHT;
	env->width = WIDTH;
	env->x_unit = 10;       //(env->width / 2) / env->column; // (width / 2) / map->line
	env->y_unit = 10; ///(env->height / 2) / env->line;
	env->z_unit = 10; ///env->y_unit / 2;
	env->mlx_ptr = mlx_init();
	env->mx = marge_x(env);
	env->my = marge_y(env);
	env->rotation_x = 0;
	env->rotation_y = 0;
	env->rotation_z = 0;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	return (env);
}

int		marge_y(t_env *env)
{
	int my;

	my = (env->height / 2) - ((env->column * env->y_unit)/ 2);
	return (my);
}

int		marge_x(t_env *env)
{
	int mx;

	mx = (env->width / 2) - ((env->line * env->x_unit) / 2);
	return (mx);
}

/*
int		hauteur_max(t_map *map)
{
	int		max;
	int		i;
	int		j;

	max = -2147483648;
	i = -1;
	while (++i < env->line)
	{
		j = -1;
		while (++j < env->column)
		{
			if (map->tab[i][j] > max)
				max = map->tab[i][j];
		}
	}
	return (max);
}*/