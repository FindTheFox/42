/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:48:27 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/02 21:05:28 by saneveu          ###   ########.fr       */
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
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->height = HEIGHT;
	env->width = WIDTH;
	env->x_unit = 32;
	env->y_unit = 16;
	env->z_unit = 8;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	return (env);
}