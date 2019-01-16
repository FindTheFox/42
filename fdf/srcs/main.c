/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/16 01:52:38 by saneveu          ###   ########.fr       */
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
		mlx_pixel_put(env->mlx, env->win, (int)line->x, (int)line->y, 0xffffff);
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

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
    ac = 0;
	(void)av;
	env->height = 500;
	env->width = 500;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 500, 500, "test windows");
	ft_line(env, 0, 0, 500, 500);
	mlx_key_hook(env->win, ft_key, NULL);
	mlx_loop(env->mlx);
	return (0);
}