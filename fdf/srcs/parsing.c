/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:52:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/11 18:11:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_column(char *l)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (l[i])
	{
		while (l[i] && (l[i] == ' ' || l[i] == '\n' || l[i] == '\t'))
			i++;
		if (l[i])
			nb++;
		while (l[i] && (l[i] != ' ' && l[i] != '\n' && l[i] != '\t'))
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
	int	i;
	int	j;

	i = -1;
	env->max_z = 0;
	env->min_z = 0;
	while (++i < env->line)
	{
		j = -1;
		if (!(map[i] = (t_map *)malloc(sizeof(t_map) * env->column)))
			return (NULL);
		while (++j < env->column)
		{
			map[i][j].ox = i;
			map[i][j].oy = j;
			map[i][j].oz = tab[i][j];
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].z = tab[i][j];
			map[i][j].z > env->max_z ? env->max_z = map[i][j].z : env->max_z;
			map[i][j].z < env->min_z ? env->min_z = map[i][j].z : env->min_z;
		}
	}
	return (map);
}

void		dim_tab(t_env *e, char **line, int *fd, char *file)
{
	*fd = 0;
	e->line = 0;
	e->column = 0;
	if ((*fd = open(file, O_RDONLY)) == -1)
		return ;
	while (get_next_line(*fd, line) > 0)
		ft_count(*line, e);
	close(*fd);
}

t_map		**ft_parse(char *file, t_env *env)
{
	int		fd;
	char	*line;
	t_map	**map;
	int		**tab;
	int		i;

	dim_tab(env, &line, &fd, file);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
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
	return (map);
}
