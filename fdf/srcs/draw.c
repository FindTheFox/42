/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:54:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/10 07:59:36 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_env *env, t_coord *c1, t_coord *c2)
{
	t_line *line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs((int)c2->x - (int)c1->x) >= ft_abs((int)c2->y - (int)c1->y))
		line->lenght = ft_abs((int)c2->x - (int)c1->x);
	else
		line->lenght = ft_abs((int)c2->y - (int)c1->y);
	line->dx = (c2->x - c1->x) / line->lenght;
	line->dy = (c2->y - c1->y) / line->lenght;
	line->x = c1->x + 0.5;
	line->y = c1->y + 0.5;
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

/*void		ft_draw1(t_map *map, t_env *env)
{
	int 	x;
	int 	y;
	int 	a;

	x = 0;
	while (x < env->line)
	{
		y = 0;
		while (y < env->column)
		{
			ft_iso2(env, map[a], x, y);
			y++;
		}
		x++;
	}
}

void		ft_draw(t_map **map, t_env *env)
{
	int a;
	t_screen *s;

	if (!(s = (t_screen *)malloc(sizeof(t_screen))))
	a = 0;
	while (a < env->line * env->column)
	{
		
	}	
}*/

t_coord		*calcul_pos(t_map **m, int i, int j, t_env *e, t_coord *c)
{
	c->x = m[i][j].x * e->x_unit + e->mx;
	c->y = m[i][j].y * e->y_unit + e->my;
	return (c);
}

t_coord		*malloc_t_coord(t_coord *c)
{
	if (!(c = (t_coord *)malloc(sizeof(t_coord))))
		exit(EXIT_FAILURE);
	return (c);
}

void		do_rectangle(t_env *e, t_map **map)
{
	int i;
	int j;
	t_coord *c1;
	t_coord *c2;

	c1 = NULL;
	c2 = NULL;
	c1 = malloc_t_coord(c1);
	c2 = malloc_t_coord(c2);
	i = 0;
	j = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->column)
		{
			if (j == e->column - 1 && i != e->line - 1)
				ft_line(e, calcul_pos(map, i, j, e, c1), calcul_pos(map, i + 1, j, e, c2));
			else if (i == e->column - 1 && j != e->column - 1)
				ft_line(e, calcul_pos(map, i, j, e, c1), calcul_pos(map, i, j + 1, e, c2));
			else if (i != e->column - 1 && j != e->column - 1)
			{
				ft_line(e, calcul_pos(map, i, j, e, c1), calcul_pos(map, i, j + 1, e, c2));
				ft_line(e, calcul_pos(map, i, j, e, c1), calcul_pos(map, i + 1, j, e, c2));
			}
			j++;
		}
		i++;
	}
}

/*
void	ft_iso2(t_env *env, t_map *map)
{
	int			a;
	t_screen	*screen;

	if (!(screen = (t_screen *)malloc(sizeof(t_screen))))
		return ;
	a = 0;
	while (a <= (env->line * env->column))
	{
		screen->x1 = (map[a].y - map[a].x) * env->x_unit + env->mx;
		screen->y1 = (map[a].y + map[a].x) * env->y_unit + env->my - map[a].z * env->z_unit;	
		screen->x2 = (map[a + 1].y - map[a + 1].x) * env->x_unit + env->mx;
		screen->y2 = (map[a + 1].y + map[a + 1].x) * env->y_unit + env->my - map[a + 1].z * env->z_unit;
		ft_line(env, screen);
		a++;
	}
	free(screen);
}
*/