/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/17 14:04:50 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define HEIGHT 500
# define WIDTH 500

typedef struct	s_line
{
	int		lenght;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;
	double	mix;
}				t_line;

typedef struct	s_env
{
	int		height;
	int		width;
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	s_map
{
	int	line;
	int column;
	int	**tab;
}				t_map;

int			main(int ac, char **av);
t_map		*ft_parse(char *file);
void		ft_line(t_env *env, float x1, float y1, float x2, float y2);
void		ft_display_map(t_map *map);

#endif