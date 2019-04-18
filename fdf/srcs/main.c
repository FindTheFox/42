/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/18 17:26:17 by saneveu          ###   ########.fr       */
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
	ft_addr(e);
	free_all(e);
	while (1)
		;
	exit(EXIT_SUCCESS);
	return (0);
}

void		ft_addr(t_env *e)
{
	printf("rot x addr = %p\n", &e->rot_x);
	printf("rot y addr = %p\n", &e->rot_y);
	printf("rot z addr = %p\n", &e->rot_z);
	printf("hauteur addr = %p\n", &e->z_height);
	printf("move x addr = %p\n", &e->move_x);
	printf("move y addr = %p\n", &e->move_y);
	printf("mlx addr = %p\n", e->mlx_ptr);
	printf("img addr = %p\n", e->img_ptr);
	printf("win ptr addr = %p\n", e->win_ptr);	
	printf("coice_color addr = %p\n", &e->choice_color);
}