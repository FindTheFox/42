/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:52:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/17 17:52:40 by saneveu          ###   ########.fr       */
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

void		ft_count(char *line, t_map *map)
{
	map->line++;
	map->column = ft_count_column(line);
	free(line);
}

t_map		*ft_parse(char *file)
{
	int		fd;
	char	*line;
	t_map	*map;
	int 	i;
	
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		ft_count(line, map);
	close(fd);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(map->tab = (int **)malloc(sizeof(int *) * (map->line + 1))))
	i = 0;
	while (get_next_line(fd, &line))
	{
		map->tab[i] = ft_intsplit(line, " \t\n");
		free(line);
		i++;
	}
	map->tab[i] = NULL;
	close(fd);
	return(map);
}