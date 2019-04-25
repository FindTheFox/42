/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:21:43 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/25 15:04:06 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# define COL 4
# define ROW 6
# define BUFF_LEN 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_verif
{
	int			hash;
	int			p;
	int			eol;
}				t_verif;

typedef struct	s_tetri
{
	char		c[4][2];
	char		letter;
}				t_tetri;

void			ft_init(char map[COL][ROW], t_verif *verif);
t_list			*ft_parser(char *file);
char			**ft_solver(t_list **list);
void			ft_display_final_map(char **final_map);
int				ft_sqrt_supp(int nb);
void			ft_b_point(char **map, int size);
int				ft_reader(int fd, char map[COL][ROW], t_verif *verif);
void			ft_free_list(t_list *list);
void			ft_letter_assignation(t_list *list);
int				ft_min_map(t_list **list);
char			**ft_create_map(int nb);
void			ft_free_map(char **map);

#endif
