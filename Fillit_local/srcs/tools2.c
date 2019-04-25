/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:49:14 by arsciand          #+#    #+#             */
/*   Updated: 2019/04/24 11:44:46 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_sqrt_supp(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

void	ft_b_point(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

void	ft_display_final_map(char **final_map)
{
	int i;

	i = 0;
	while (final_map[i])
		ft_putendl(final_map[i++]);
}

void	ft_free_map(char **map)
{
	int		i;

	i = -1;
	if (map != NULL && *map != NULL)
	{
		while (map[++i] != NULL)
		{
			free(map[i]);
			map[i] = NULL;
		}
		free(map);
	}
}
