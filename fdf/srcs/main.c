/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/08 18:11:06 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *mlx, int x1, int y1, int x2, int y2)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs(x2 - x1) >= ft_abs(y2 - y1))
		line->lenght = ft_abs(x2 - x1);
	else
		line->lenght = ft_abs(y2 - y1);
	line->dx = (x2 - x1) / line->lenght;
	line->dy = (y2 - y1) / line->lenght;
	line->x = x1 + 0.5;
	line->y = y1 + 0.5;
	line->i = 1;
	while (line->i <= line->lenght && line->x < mlx->width
			&& line->y < mlx->height)
	{
		line->mix = line->i / (double)line->lenght;
		mlx_pixel_put(mlx->mlx, mlx->win, line->x, line->y, 0xFFFFFF);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
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
	ft_line(env, 15, 25, 156, 500);
	mlx_loop(env->mlx);
	return (0);
}