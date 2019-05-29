/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:43:13 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/29 18:32:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_pixel_img(int *img, t_index i, t_index size, int color)
{
	if (i.x >= 0 && i.y >= 0 && i.y < size.y && i.x < size.x)
        img[(int)(i.x + size.x * i.y)] = color;
}