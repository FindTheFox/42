/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/01/18 18:33:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define HEIGHT 800
# define WIDTH 600

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

typedef struct	s_img
{
	int		*data;
	int		bpp;
	int		s_l;
	int		endian;
	void	*img_ptr;
}				t_img;

typedef struct	s_env
{
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
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
t_env		*setup_mlx(t_env *env);
void 		color_pixel_img(int *data, int x, int y, int color, t_env *env);
void		setup_img(t_env *env);

#endif