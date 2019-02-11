/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/11 08:27:58 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, t_env *e)
{
	(void)e;
	ft_putnbr(key);
	if (key == 86 || key == 91 || key == 88 || key == 87)
	{
		ft_clear_img(e);
		ft_rotation(key, e);
		do_rectangle(e, e->map);
		mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	}
	if (key == 53)
		exit(0);
	return (0);
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

int		main(int ac, char **av)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac != 2)
		return(ft_usage());
	if (!(env->map = ft_parse(av[1], env)))
		return (0);
	if (!(env = setup_mlx(env)))
		return(0);
	setup_img(env);
	ac = 0;
	//print_map_elem(env, env->map);
	//ft_draw(env->map, env);
	do_rectangle(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	mlx_key_hook(env->win_ptr, ft_key, env);
	mlx_mouse_hook(env->win_ptr, ft_key_mouse, env);
	mlx_loop(env->mlx_ptr);
	free(env->map);
	free(env);
	return (0);
}