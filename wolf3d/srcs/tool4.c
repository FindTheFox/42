/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:50:05 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/12 20:33:21 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void            switch_monster(t_wolf *d)
{
    if (d->nmistyle == 0)
    {
        d->nmistyle = 1;
        sprites_monsters(d);
    }
    else
    {
        d->nmistyle = 0;
        sprites_monsters2(d);
    }
}

t_rgba          fill_rgb(int c)
{
	t_rgba rgb;
	rgb.r = c / (256 * 256);
	rgb.g = (c / 256) % 256;
	rgb.b = c % 256;
	return (rgb);
}

int             rgb_to_hsv(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}
