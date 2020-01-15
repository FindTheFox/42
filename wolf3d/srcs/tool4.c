/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:50:05 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/15 22:11:17 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void           free_surfaces_monsters(t_wolf *data)
{
    SDL_FreeSurface(data->sprite[7].img);
	SDL_FreeSurface(data->sprite[8].img);
	SDL_FreeSurface(data->sprite[9].img);
	SDL_FreeSurface(data->sprite[10].img);
	SDL_FreeSurface(data->sprite[11].img);
	SDL_FreeSurface(data->sprite[12].img);
	SDL_FreeSurface(data->sprite[13].img);
	SDL_FreeSurface(data->sprite[14].img);
	SDL_FreeSurface(data->sprite[15].img);
}

void            switch_monster(t_wolf *d)
{
    if (d->nmistyle == 0)
    {
        free_surfaces_monsters(d);
        d->nmistyle = 1;
        sprites_monsters(d);
    }
    else if (d->nmistyle == 1)
    {
        free_surfaces_monsters(d);
        d->nmistyle = 0;
        sprites_monsters2(d);
    }
}
