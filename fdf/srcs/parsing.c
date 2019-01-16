/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:52:35 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/16 02:32:06 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list		ft_parse(char *file, t_env env)
{
	int fd;

	if (!(fd = open(file)))
		return ;
	while(ft_reader(fd, env))
	{
		ft_fill_list()
	}
}