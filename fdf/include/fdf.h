/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/24 10:19:57 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>  ///////////////
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# define HEIGHT 1080
# define WIDTH	1920
# define V_ROT	5.
# define V_ROT_Z (M_PI / 360) 
# define V_MV	20.
# define V_ZOOM 2
# define V_Z_HEIGHT 5.
# define NEAR	0.1
# define FAR	100.
# define FOV	90.


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

typedef	struct	s_matrix
{
	float x[4];
	float y[4];
	float z[4];
	float w[4];
}				t_matrix;

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
	int		center_width;
	int		center_height;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	double	scale;
	int		max_z;
	int		min_z;
	int		center_x;
	int		center_y;
	int		z_height;
	double	move_x;
	double	move_y;
}				t_env;


int			main(int ac, char **av);
t_map		**ft_parse(char *file, t_env *env);
void		ft_line(t_env *env, float x1, float y1, float x2, float y2, int color);
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
void		transform(t_env *e);
void		marge_apply(t_env *e, t_map **m, int i, int j);
void		calcul_apply(t_env *e, t_map **map, int i, int j);
int			deal_key(int key, t_env *e);
void		tile_apply(t_map **m, t_env *e);
void		put_to_screen(t_env *e);
void		reset(t_env *e);
void        rotate(t_env *e, double *axe, double degree);
void		end_program(t_env *e);
void        zoom(t_env *e, int zoom);
void		get_center(t_env *env);
void        move_x(t_env *e, double pixel);
void        move_y(t_env *e, double pixel);
void		apply_center(t_env *e, t_map **m, int i, int j);
void        iso(t_env *e);
void        para(t_env *e);
void		set_matrix(t_env *e, t_matrix *mt);
void		mult_perspective(t_env *e, t_map **m, t_matrix mt, int i, int j);
void        hauteur(t_env *e, double z_speed);
void		show_commande(t_env *e);

void		display_img(t_env *e);
void		do_tmp(t_map **m, int i, int j, int A);
void		turn_and_draw(t_env *e);

#endif