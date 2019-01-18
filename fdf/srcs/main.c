/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/18 19:09:20 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *env, float x1, float y1, float x2, float y2)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs((int)x2 - (int)x1) >= ft_abs((int)y2 - (int)y1))
		line->lenght = ft_abs((int)x2 - (int)x1);
	else
		line->lenght = ft_abs((int)y2 - (int)y1);
	line->dx = (x2 - x1) / line->lenght;
	line->dy = (y2 - y1) / line->lenght;
	line->x = x1 + 0.5;
	line->y = y1 + 0.5;
	line->i = 1;
	while (line->i++ <= line->lenght)
	{
		color_pixel_img(env->img->data, (int)line->x, (int)line->y, 0xffffff, env);
		line->x += line->dx;
		line->y += line->dy;
	}
	free(line);
}

int		ft_key(int key, void *truc)
{
	(void)truc;
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env *env;
	t_map *map;
	t_img *img;

	env = NULL;
	map = NULL;
	img = NULL;
	if (!(env = setup_mlx(env)))
		return(0);
	setup_img(env);
	ac = 0;
	(void)av;
	ft_line(env, 0, 0, 500, 500);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->img_ptr, 0, 0);
	mlx_key_hook(env->win_ptr, ft_key, NULL);
	mlx_loop(env->mlx_ptr);
	//map = ft_parse(av[1]);
	//ft_display_map(map);
	return (0);
}