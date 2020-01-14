/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:50:05 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/14 20:26:31 by saneveu          ###   ########.fr       */
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

void            free_minimap(t_wolf *d)
{
    //int i;
    free(d->rect);
    //i = 0;
}