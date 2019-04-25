/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:05:26 by saneveu           #+#    #+#             */
/*   Updated: 2018/12/25 14:23:54 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fix_neg(t_tetri *t)
{
	int		a;
	int		b;

	a = 0;
	b = 1;
	while (a < 4)
	{
		if (t->c[a][b] < 0)
		{
			a = 0;
			while (a < 4)
				t->c[a++][b] += 1;
		}
		a++;
	}
}

void		ft_absolut_coord(t_tetri *t)
{
	int		a;

	while (t->c[0][0] != 0)
	{
		a = 0;
		while (a < 4)
			t->c[a++][0] -= 1;
	}
	while (t->c[0][1] != 0)
	{
		a = 0;
		while (a < 4)
			t->c[a++][1] -= 1;
	}
	ft_fix_neg(t);
}

void		ft_fill_coord(char tab[COL][ROW], t_tetri *t)
{
	int		x;
	int		y;
	int		a;
	int		b;

	x = 0;
	y = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 5)
		{
			if (tab[a][b] == '#')
			{
				t->c[x][y] = a;
				t->c[x][y + 1] = b;
				x++;
			}
			b++;
		}
		a++;
	}
	ft_absolut_coord(t);
}

int			ft_fill_list(char map[COL][ROW], t_list **list)
{
	t_tetri	*t;

	if (!(t = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	ft_fill_coord(map, t);
	ft_lstpushback(list, ft_lstnew(t, sizeof(t_tetri)));
	free(t);
	return (1);
}

t_list		*ft_parser(char *file)
{
	char	map[COL][ROW];
	int		fd;
	int		res;
	t_verif	verif;
	t_list	*list;

	if (!(fd = (open(file, O_RDONLY))))
		return (NULL);
	list = NULL;
	res = 1;
	while (res == 1)
	{
		if ((res = ft_reader(fd, map, &verif)) == -1)
		{
			ft_free_list(list);
			return (NULL);
		}
		if (!(ft_fill_list(map, &list)))
			return (NULL);
		ft_bzero(map, sizeof(map));
	}
	ft_letter_assignation(list);
	close(fd);
	return (list);
}
