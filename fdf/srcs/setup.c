/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:48:27 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/24 07:30:25 by saneveu          ###   ########.fr       */
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
	env->mlx_ptr = mlx_init();
	env->scale = fmin(env->width / 2 / (env->line + env->max_z),
		env->height / 2 / (env->column + env->max_z));
	env->center_width = env->width / 2;//(env->width - (env->column * env->scale)) / 2;
	env->center_height = env->height / 2;//(env->height - (env->line * env->scale)) / 2;
	env->z_height = env->max_z;
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->move_x = 0;
	env->move_y = 0;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	
	return (env);
}
