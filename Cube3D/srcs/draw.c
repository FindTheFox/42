/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:33:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 04:40:24 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void        draw_triangle(t_env *e, t_vec p[3])
{
    SDL_RenderDrawLine(e->rend, p[0].x, p[0].y, p[1].x, p[1].y);
    SDL_RenderDrawLine(e->rend, p[1].x, p[1].y, p[2].x, p[2].y);
    SDL_RenderDrawLine(e->rend, p[2].x, p[2].y, p[0].x, p[0].y);
} 