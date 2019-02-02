/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/02 01:27:25 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>  ///////////////
# include <fcntl.h>
# include "libft.h"
# define HEIGHT 600
# define WIDTH 800

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

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_map
{
	int	line;
	int column;
	int	**tab;
}				t_map;

typedef struct	s_env
{
	t_map	*map;
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*str;
	float	mx;
	float	my;
	t_coord *C1;
	t_coord *C2;

}				t_env;

int			main(int ac, char **av);
t_map		*ft_parse(char *file);
void		ft_line(t_env *env, float x1, float y1, float x2, float y2);
void		ft_display_map(t_map *map);
t_env		*setup_mlx(t_env *env);
void 		color_pixel_img(t_env *env, int x, int y, int color);
void		setup_img(t_env *env);
int 		ft_usage();

void		paint_all_in_white(t_env *env);

#endif