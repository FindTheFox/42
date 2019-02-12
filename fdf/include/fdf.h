/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/12 06:31:39 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>  ///////////////
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# define HEIGHT 1080
# define WIDTH	1920
# define X		1
# define Y		2
# define Z		3

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

typedef	struct	s_coord
{
	float x;
	float y;
}				t_coord;

typedef struct	s_map
{
	float 	x;
	float 	y;
	float	z;
	float	rx;
	float	ry;
	float	rz;
	float	fx;
	float	fy;
	float	fz;
	float	tx;
	float	ty;
	float	tz;
}				t_map;

typedef struct	s_screen
{
	float		x1;
	float		x2;
	float	 	y1;
	float		y2;
	int			color;
}				t_screen;

typedef struct	s_env
{	
	t_map	**map;
	int		line;
	int 	column;
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*str;
	int		mx;
	int		my;
	double	x_unit;
	double	y_unit;
	double	z_unit;
	double  rotation_x;
	double  rotation_y;
	double  rotation_z;
	double  speed;
	char	rot;
	int		mod;
	int		angle;
}				t_env;


int			main(int ac, char **av);
t_map		**ft_parse(char *file, t_env *env);
void		ft_line(t_env *env, float x1, float y1, float x2, float y2);
void		ft_display_map(t_map *map);
t_env		*setup_mlx(t_env *env);
void 		color_pixel_img(t_env *env, int x, int y, int color);
void		setup_img(t_env *env);
int 		ft_usage();
void		ft_draw(t_env *env);
int			hauteur_max(t_map *map);
int			marge_x(t_env *env);
int			marge_y(t_env *env);
t_map		**ft_parse_helper(t_map **map, int **tab, t_env *env);
void		do_rectangle(t_env *env, t_map **map);
void		ft_rotation(int key, t_env *e);
void		ft_rotation_x(t_env *e, t_map m);
void		ft_rotation_y(t_env *e, t_map m);
void		ft_rotation_z(t_env *e, t_map m);
void		display_tab(int **tab, t_env *env);
void		print_map_elem(t_env *env, t_map **map);
void		ft_clear_img(t_env *e);
double 		ft_to_radian(double degree);
void		tile_apply(t_map **m, t_env *e);
void		paint_all_in_white(t_env *env);
void		marge_apply(t_map **m, t_env *e);
void		ft_transform(t_env *e);
void		ft_calculate(t_env *e, t_map m, char c);

void		display_img(t_env *e);
void		do_tmp(t_map **m, int i, int j, int A);

#endif