/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 22:06:25 by saneveu          ###   ########.fr       */
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
# define SPEED_ROT	5
# define SPEED_MV	5



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
	float	ox;
	float	oy;
	float	oz;
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
	int		center_x;
	int		center_y;
	int		rot_x;
	int		rot_y;
	int		rot_z;
//	char	rot; //#//
//	int		mod; //#//
	double	scale;
	int		max_z;
	int		min_z;
	int		z_height;
	int		move_x;
	int		move_y;
}				t_env;


int			main(int ac, char **av);
t_map		**ft_parse(char *file, t_env *env);
void		ft_line(t_env *env, float x1, float y1, float x2, float y2);
t_env		*setup_mlx(t_env *env);
void 		color_pixel_img(t_env *env, int x, int y, int color);
void		setup_img(t_env *env);
int 		ft_usage();
void		draw_img(t_env *env);
int			hauteur_max(t_map *map);
t_map		**ft_parse_helper(t_map **map, int **tab, t_env *env);
void		do_rectangle(t_env *env, t_map **map);
void		event_rotation(int key, t_env *e);
void		ft_rotation_x(t_env *e, t_map m);
void		ft_rotation_y(t_env *e, t_map m);
void		ft_rotation_z(t_env *e, t_map m);
void		display_tab(int **tab, t_env *env);
void		print_map_elem(t_env *env, t_map **map);
void		ft_clear_img(t_env *e);
double 		to_radian(double degree);
void		tile_apply(t_map **m, t_env *e);
void		paint_all_in_white(t_env *env);
void		marge_apply(t_map **m, t_env *e);
void		transform(t_env *e);
void		calcul_apply(t_env *e, t_map **map, int i, int j);
int			deal_key(int key, t_env *e);
void		tile_apply(t_map **m, t_env *e);
void		marge_apply(t_map **m, t_env *e);
void		put_to_screen(t_env *e);
void		reset(t_env *e);
void        rotate(t_env *e, int *axe, int degree);
void		end_program(t_env *e);

void		display_img(t_env *e);
void		do_tmp(t_map **m, int i, int j, int A);
void		turn_and_draw(t_env *e);


#endif