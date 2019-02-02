/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:05 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/02 01:34:09 by saneveu          ###   ########.fr       */
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
	while (line->i <= line->lenght && line->x < env->width && line->y < env->height)
	{
		color_pixel_img(env, (int)line->x, (int)line->y, 0xffffff);
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, line->x, line->y, 0xffffff);
		//env->img_str[((int)line->y * env->width) + (int)line->x] = 0xffffff;
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}

int		ft_key(int key, void *truc)
{
	(void)truc;
	ft_putnbr(key);
	if (key == 53)
		exit(0);
	return (0);
}

int		ft_key_mouse(int key, int x, int y, t_env *env)
{
	ft_putnbr(key);
	if (key == 1)
	{
		//if (!(env->C1 = (t_coord *)malloc(sizeof(t_coord))))
		//	return (0);
		env->C1->x = x;
		env->C1->y = y;
		printf("| x1 = %d |", x);
		printf("| CX1 = %d |", env->C1->x);
	}
	if (key == 2)
	{
		//if (!(env->C2 = (t_coord *)malloc(sizeof(t_coord))))
		//	return (0);
		env->C2->x = x;
		env->C2->y = y;
		ft_line(env, env->C1->x, env->C1->y, env->C2->x, env->C2->y);
		printf("| x2 = %d |", x);
		printf("| CX1 = %d |", env->C1->x);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env *env;

	env = NULL;
	if (ac != 2)
		return(ft_usage());
	if (!(env = setup_mlx(env)))
		return(0);
	env->map = ft_parse(av[1]);
	setup_img(env);
	ac = 0;
	//ft_line(env, 65, 65, 300, 300);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	mlx_key_hook(env->win_ptr, ft_key, NULL);
	mlx_hook(env->win_ptr, (1<<8), (1<<8), ft_key_mouse, env);
	mlx_hook(env->win_ptr, (1<<9), (1<<9), ft_key_mouse, env);
	mlx_loop(env->mlx_ptr);
	//ft_display_map(map);
	free(env->map);
	free(env);
	return (0);
}