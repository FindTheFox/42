/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:48:27 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 22:10:10 by saneveu          ###   ########.fr       */
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
	printf("scale = %f\n", env->scale);
	env->center_x = (env->width - (env->column * env->scale)) / 2;
	env->center_y = (env->height - (env->line * env->scale)) / 2;
	printf("center_x = %d\ncenter_y = %d\n", env->center_x, env->center_y);
	env->z_height = 1;
	env->rot_x = 45;
	env->rot_y = 75;
	env->move_x = 0;
	env->move_y = 0;
//	env->mod = 2;
//	env->angle = 0;
//	env->rot = X;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	
	return (env);
}
