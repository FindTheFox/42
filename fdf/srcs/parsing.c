/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:52:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/10 16:00:19 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_column(char *line)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
			i++;
		if (line[i])
			nb++;
		while (line[i] && (line[i] != ' ' && line[i] != '\n' && line[i] != '\t'))
			i++;
	}
	return (nb);
}

void		ft_count(char *line, t_env *env)
{
	env->line++;
	env->column = ft_count_column(line);
	free(line);
}

t_map		**ft_parse_helper(t_map **map, int **tab, t_env *env)
{
	int 	i;
	int		j;

	i = 0;
	env->max_z = 0;
	env->min_z = 0;
	while (i < env->line)
	{
		j = 0;
		if (!(map[i] = (t_map *)malloc(sizeof(t_map) * env->column)))
			return (NULL);
		while (j < env->column)
		{
			map[i][j].ox = i;
			map[i][j].oy = j;
			map[i][j].oz = tab[i][j];
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].z = tab[i][j];
			map[i][j].z > env->max_z ? env->max_z = map[i][j].z : env->max_z;
			map[i][j].z < env->min_z ? env->min_z = map[i][j].z : env->min_z;
			j++;
		}
		i++;
	}
	return (map);
}

t_map		**ft_parse(char *file, t_env *env)
{
	int		fd;
	char	*line;
	t_map	**map;
	int		**tab;
	int 	i;
	
	fd = 0;
	env->line = 0;
	env->column = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		ft_count(line, env);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(tab = (int **)malloc(sizeof(int *) * (env->line))))
		return (0);
	if (!(map = (t_map **)malloc(sizeof(t_map *) * env->line)))
		return (0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab[i++] = ft_intsplit(line, " \t\n");
		free(line);
	}
	map = ft_parse_helper(map, tab, env);
	free_tab(tab);
	close(fd);
	return(map);
}