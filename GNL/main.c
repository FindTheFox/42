/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:55:15 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/19 23:18:38 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;

	fd = open("author", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
}