/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:59:52 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/22 18:09:57 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# include <stdio.h>

# define HEIGHT 1080
# define WIDTH	1920
# define V_ROT	5
# define V_ROT_Z 1
# define V_MV	20.
# define V_ZOOM 1
# define V_Z_HEIGHT 0.1
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

typedef struct	s_map
{
	float	x;
	float	y;
	float	z;
	float	oy;
	float	ox;
	float	oz;

}				t_map;

typedef struct	s_screen
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			color_1;
	int			color_2;
}				t_screen;

typedef struct	s_env
{
	t_map		**map;
	t_screen	*s;
	int			line;
	int			column;
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*str;
	int			center_width;
	int			center_height;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		scale;
	int			max_z;
	int			min_z;
	int			center_x;
	int			center_y;
	double		z_height;
	double		move_x;
	double		move_y;
	int			choice_color;
}				t_env;

int				main(int ac, char **av);
t_map			**ft_parse(char *file, t_env *env);
void			ft_line(t_env *env, t_screen *s, int color);
t_env			*setup_mlx(t_env *env);
void			color_pixel_img(t_env *env, int x, int y, int color);
void			setup_img(t_env *env);
int				ft_usage(void);
void			draw_img(t_env *env);
int				hauteur_max(t_map *map);
t_map			**ft_parse_helper(t_map **map, int **tab, t_env *env);
void			do_rectangle(t_env *env, t_map **map);
void			event_rotation(int key, t_env *e);
void			ft_clear_img(t_env *e);
double			to_radian(double degree);
void			transform(t_env *e);
void			marge_apply(t_env *e, t_map **m, int i, int j);
void			calcul_apply(t_env *e, t_map **map, int i, int j);
int				deal_key(int key, t_env *e);
void			tile_apply(t_map **m, t_env *e);
void			put_to_screen(t_env *e);
void			reset(t_env *e);
void			rotate(t_env *e, double *axe, double degree);
int				end_program(void *e);
void			zoom(t_env *e, int zoom);
void			get_center(t_env *env);
void			move(t_env *e, double *axe, double pixel);
void			apply_center(t_env *e, t_map **m, int i, int j);
void			iso(t_env *e);
void			para(t_env *e);
void			hauteur(t_env *e, double z_speed);
void			show_commande(t_env *e);
void			choose_color(t_env *e, float z, t_screen *s);
void			color_event(t_env *e);
int				rota_event(int key, t_env *e);
void			event(t_env *e);
int				color_alt(float z);
void			free_tab(int **tab, t_env *e);
void			free_map(t_map **tab);
void			dim_tab(t_env *e, char **line, int *fd, char *file);
void			assign_color(t_screen *c, int color1, int color2);
void			coord(t_screen *s, int x1, int y1, int x2, int y2);
void			show_commande2(t_env *e, char *line);
int				test_file(char *file);
void			free_all(t_env *e);
t_screen		*malloc_struct(t_screen *s);
void			ft_addr(t_env *e);

#endif
