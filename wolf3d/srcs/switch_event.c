/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:09:57 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/30 20:11:00 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
 
void		switch_fog(t_wolf *d)
{
	d->fog++;
	if (d->fog == 4)
		d->fog = 0;
}

void			switch_texture(t_wolf *data)
{
	free_surfaces(data, 1);
	if (data->style == 0)
	{
		data->style = 1;
		sprites_textures_maze(data);
	}
	else if (data->style == 1)
	{
		data->style = 2;
		sprites_textures(data);
	}
	else
	{
		data->style = 0;
		sprites_textures_asylum(data);
	}
}
