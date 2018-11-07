/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:42:18 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 16:00:13 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DISPLAY_H
# define LIB_DISPLAY_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUFF 64

void	ft_putchar(char c);
int		main(int ac, char **av);
int 	ft_reader(int fd);
void	ft_putstr(char *s);
char	*ft_init_buffer(char *buffer);

#endif
