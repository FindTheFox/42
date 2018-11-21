/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:55:15 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/21 13:09:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	while(get_next_line(fd, &line) == 1)
	printf("%s\n", line);
	close(fd);
}