/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:24:39 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/25 15:06:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_list	*list;
	char	**map;

	map = NULL;
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit [source_file]");
		return (0);
	}
	if (!(list = ft_parser(av[1])))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(map = ft_solver(&list)))
	{
		ft_free_map(map);
		ft_putendl("error");
		return (0);
	}
	else
	{
		ft_display_final_map(map);
		ft_free_map(map);
	}
	return (0);
}
