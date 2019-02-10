/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/10 07:42:38 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>  ///////////////
# include <fcntl.h>
# include "libft.h"
# define HEIGHT 1080
# define WIDTH 1920

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
	int 	x;
	int 	y;
	int		z;
	float 	cx;
	float	cy;
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
}				t_env;


int			main(int ac, char **av);
t_map		**ft_parse(char *file, t_env *env);
void		ft_line(t_env *env, t_coord *c1, t_coord *c2);
void		ft_display_map(t_map *map);
t_env		*setup_mlx(t_env *env);
void 		color_pixel_img(t_env *env, int x, int y, int color);
void		setup_img(t_env *env);
int 		ft_usage();
void		ft_draw(t_map **map, t_env *env);
void		ft_iso(t_env *mlx, t_map *map, int i, int j);
int			hauteur_max(t_map *map);
int			marge_x(t_env *env);
int			marge_y(t_env *env);
void		ft_para(t_env *env, t_map *map, int i, int j);
t_map		**ft_parse_helper(t_map **map, int **tab, t_env *env);
void		ft_iso2(t_env *env, t_map *map);
void		do_rectangle(t_env *env, t_map **map);

void		display_tab(int **tab, t_env *env);
void		print_map_elem(t_env *env, t_map **map);

void		paint_all_in_white(t_env *env);

#endif