/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:46:08 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 15:59:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_display.h"

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

char	*ft_init_buffer(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
		buffer[i++] = '\0';
	return (buffer);
}

int		ft_reader(int fd)
{
	char	buffer[BUFF + 1];
	ssize_t res;

	res = 1;
	buffer[BUFF] = '\0';
	while (res)
	{
		ft_init_buffer(buffer);
		res = read(fd, buffer, BUFF);
		ft_putstr(buffer);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	else if (ac >= 3)
	{
		ft_putstr("Too many arguments.\n");
	}
	else
		close(ft_reader(open(av[1], O_RDONLY)));
	return (0);
}