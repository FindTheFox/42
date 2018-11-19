/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:57:21 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/19 23:19:43 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_chrandsub(char *buff)
{
	int		i;
	char	*out;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	out = ft_strsub(buff, 0, i);
	return (out);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save[1024];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				res;

	if (fd < 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		tmp = ft_chrandsub(buff);
		if (save[fd] == NULL)
			save[fd] = ft_strnew(1);
		tmp = ft_strjoin(save[fd], tmp);
		free(save[fd]);
		save[fd] = ft_strcpy(save[fd], tmp);
		if (!ft_strchr(save[fd], '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 || (save[fd] == NULL || save[fd][0] == '\0'))
		return (0);
	*line = ft_strdup(save[fd]);
	return (1);
}