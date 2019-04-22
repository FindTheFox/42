/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:54:22 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/22 17:38:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_usage(void)
{
	ft_putendl("usage : ./fdf [map_file]");
	return (0);
}

void		color_pixel_img(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < env->height && x < env->width)
		env->str[x + env->width * y] = color;
}

void		ft_clear_img(t_env *e)
{
	int i;

	i = 0;
	while (i < e->width * e->height)
	{
		if (e->str[i] != 0)
			e->str[i] = 0;
		i++;
	}
}

void		free_tab(int **tab, t_env *e)
{
	int i;

	i = 0;
	while (i < e->line)
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void		free_map(t_map **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void		free_all(t_env *e)
{
	ft_clear_img(e);
	free(e->s);
	e->s = NULL;
	free_map(e->map);
	free(e);
	e = NULL;
}
