/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:48:27 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/17 17:24:26 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			setup_img(t_env *env)
{
	int		bpp;
	int		s_l;
	int		endian;

	env->img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->str = (int *)mlx_get_data_addr(env->img_ptr, &bpp, &s_l, &endian);
}

t_env			*setup_mlx(t_env *env)
{
	env->height = HEIGHT;
	env->width = WIDTH;
	env->mlx_ptr = mlx_init();
	env->scale = fmin(env->width / 2 / (env->line + env->max_z),
		env->height / 2 / (env->column + env->max_z));
	env->center_width = env->width / 2;
	env->center_height = env->height / 2;
	env->z_height = 0.2;
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
	env->move_x = 0;
	env->move_y = 0;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "fdf");
	env->choice_color = 0;
	return (env);
}

void			show_commande(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 20, 0xffffff,
		"(2 & 8) Axe X rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 20, 0x00e60000,
		ft_itoa(e->rot_x));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 40, 0xffffff,
		"(4 & 6) Axe Y rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 40, 0x00e60000,
		ft_itoa(e->rot_y));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 60, 0xffffff,
		"(7 & 9) Axe z rotation de :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 300, 60, 0x00e60000,
		ft_itoa(e->rot_z));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 80, 0xffffff,
		"(+ & -) Zoom =");
	show_commande2(e);
}

void			show_commande2(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 180, 80, 0x3225428f,
		ft_itoa(e->scale));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 100, 0xffffff,
		"(Up & Down) z_height =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 250, 100, 0x3225428f,
		ft_itoa(e->z_height));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 120, 0xffffff,
		"(C) Color =");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 140, 120, 0x3225428f,
		ft_itoa(e->choice_color));
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 140, 0xffffff,
		"(R) Reset");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 160, 0xffffff,
		"(I) Iso");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 180, 0xffffff,
		"(P) Para");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 20, 200, 0xffffff,
		"(Arrow) Move");
}

int				test_file(char *file)
{
	int i;

	i = -1;
	while (file[++i])
		if (file[i] == '.' && file[i + 1] == 'f'
		&& file[i + 2] == 'd' && file[i + 3] == 'f')
			return (1);
	ft_putendl("name of file invalid");
	return (0);
}
