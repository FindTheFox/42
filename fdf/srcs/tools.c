/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/18 19:03:21 by saneveu          ###   ########.fr       */
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

void 		color_pixel_img(int *data, int x, int y, int color, t_env *env)
{
	data[y * env->width + x] = color;
}

void		setup_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return ;
	env->img = img;
	env->img->img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->img->data = (int *)mlx_get_data_addr(env->mlx_ptr, &img->bpp, &img->s_l, &img->endian);
}

t_env		*setup_mlx(t_env *env)
{
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->height = 600;
	env->width = 800;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	return (env);
}