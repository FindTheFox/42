/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 21:00:32 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	draw_img(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	//turn_and_draw(env);
	mlx_key_hook(env->win_ptr, deal_key, env);
	//mlx_mouse_hook(env->win_ptr, ft_key_mouse, env);
	mlx_loop(env->mlx_ptr);
	free(env->map);
	free(env);
	return (0);
}

void		end_program(t_env *e)
{
	//========free all=========//
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(0);
}