/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:35 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/20 16:56:54 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		ft_nb_link(char map[COL][ROW])
{
	int		x;
	int		y;
	int		link;

	link = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 5)
		{
			if (map[x][y] == '#')
			{
				if (map[x + 1][y] == '#')
					link += 2;
				if (map[x][y + 1] == '#')
					link += 2;
			}
			y++;
		}
		x++;
	}
	return (link);
}

int		ft_verif(char *c, t_verif *verif)
{
	if (*c == '#')
		verif->hash += 1;
	else if (*c == '.')
		verif->p += 1;
	else if (*c == '\n')
		verif->eol += 1;
	else
		return (-1);
	return (1);
}

int		ft_next_tetri(int fd, char *buff)
{
	int ret;

	ret = 0;
	if ((ret = read(fd, buff, 1)) == 0)
		return (0);
	if (*buff == '\n')
		return (1);
	else if (*buff == '.' || *buff == '#')
		return (-1);
	return (0);
}

int		ft_check_read(t_verif *verif, int res)
{
	if ((verif->hash != 4 || verif->p != 12 || verif->eol != 4)
			|| !(res == 6 || res == 8))
		return (-1);
	return (0);
}

int		ft_reader(int fd, char map[COL][ROW], t_verif *verif)
{
	char	buff[BUFF_LEN];
	int		x;
	int		y;
	int		res;

	ft_init(map, verif);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 5)
		{
			if (((res = read(fd, buff, 1)) > 0) && (ft_verif(buff, verif) == 1))
			{
				if (*buff == '\n' && y == 0)
					return (-1);
				map[x][y++] = *buff;
			}
			else
				return (-1);
		}
		map[x++][y] = '\0';
	}
	res = ft_nb_link(map);
	return (ft_check_read(verif, res) == -1 ? -1 : ft_next_tetri(fd, buff));
}
