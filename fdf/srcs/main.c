/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/25 19:34:09 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac != 2)
		return (ft_usage());
	if (!(env->map = ft_parse(av[1], env)))
		return (0);
	if (!(env = setup_mlx(env)))
		return (0);
	setup_img(env);
	ac = 0;
	draw_img(env);
	event(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

void		event(t_env *e)
{
	mlx_key_hook(e->win_ptr, deal_key, e);
	mlx_hook(e->win_ptr, 2, (1L << 0), rota_event, e);
	mlx_hook(e->win_ptr, 17, (1L << 17), end_program, e);
}

int			end_program(void *e)
{
	mlx_clear_window(((t_env*)e)->mlx_ptr, ((t_env*)e)->win_ptr);
	mlx_destroy_image(((t_env*)e)->mlx_ptr, ((t_env*)e)->img_ptr);
	mlx_destroy_window(((t_env*)e)->mlx_ptr, ((t_env*)e)->win_ptr);
	free_all(e);
	exit(EXIT_SUCCESS);
	return (0);
}
