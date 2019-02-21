/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:08:58 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 22:06:45 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double 	    to_radian(double degree)
{
    double radian;

    if (degree == 0)
        return (0);
    radian = degree * (M_PI / 180);
	return (radian);
}

void        rotate(t_env *e, int *axe, int degree)
{
    int d;

    d = *axe + degree;
    if (d >= 360)
        *axe = 0;
    else if (d <= 0)
        *axe = 355;
    else
        *axe = d;
    draw_img(e);
}

/*
void		tile_apply(t_map **m, t_env *e)
{
	int i;
	int j;

	i = -1;
//	printf("scale = %f\n\n", e->scale);
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].rx = m[i][j].x * e->scale;
			m[i][j].ry = m[i][j].y * e->scale;
		}
	}
}

void		marge_apply(t_map **m, t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->line)
	{
		j = -1;
		while (++j < e->column)
		{
			m[i][j].fx = m[i][j].rx + (e->mx - m[e->line / 2][e->column / 2].rx);
			m[i][j].fy = m[i][j].ry + (e->my - m[e->line / 2][e->column / 2].ry);
		}
	}
}
*/