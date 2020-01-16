/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:05:22 by maboye            #+#    #+#             */
/*   Updated: 2020/01/16 15:37:45 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		in_wall(t_wolf *data)
{
	int	i;

	i = -1;
	while (++i < data->map.len)
		if (data->pfdata.list[i].bobstacle == 1)
		{
			if (distance_calc(data->player.x,
					data->player.y,
					data->pfdata.list[i].x + 0.5f,
					data->pfdata.list[i].y + 0.5f) < 0.55f)
				return (1);
		}
	return (0);
}

static int		is_outrange(t_wolf *data)
{
	t_object	*head;

	if (data->player.y < 0 || data->player.y > data->map.height)
		return (1);
	else if (data->player.x < 0 || data->player.x > data->map.width)
		return (1);
	if (in_wall(data) == 1)
		return (1);
	head = data->monster;
	while (data->monster)
	{
		if (distance_calc(data->player.x, data->player.y,
		data->monster->x, data->monster->y) < 0.25)
		{
			data->monster = head;
			return (1);
		}
		data->monster = data->monster->next;
	}
	data->monster = head;
	return (0);
}

static void		move_maker(t_wolf *data, double sx, double sy)
{
	data->player.x += sx;
	data->player.y += sy;
	if (is_outrange(data) == 1)
	{
		data->player.x -= sx;
		data->player.y -= sy;
		SDL_FlushEvent(SDL_KEYDOWN);
	}
	data->player.pos = (int)data->player.x
		+ data->map.width * (int)data->player.y;
}

static void		move_lateral(t_wolf *d, int lat)
{
	double dx;
	double dy;

	dx = lat * d->player.diry * d->mv_speed / 2;
	dy = -lat * d->player.dirx * d->mv_speed / 2;
	if (is_outrange(d) == 0)
	{
		d->player.x += dx;
		d->player.y += dy;
		SDL_FlushEvent(SDL_KEYDOWN);
		d->player.pos = (int)d->player.x
			+ d->map.width * (int)d->player.y;
	}
}

void			movements(t_wolf *data)
{
	float	shift;

	shift = data->key[SHIFT] ? 1.5f : 1;
	if (data->key[KE])
		mouse(data, 5, 1);
	if (data->key[KQ])
		mouse(data, 5, -1);
	if (data->key[KA])
		move_lateral(data, 1);
	if (data->key[KD])
		move_lateral(data, -1);
	if (data->key[KW])
		move_maker(data, data->player.dirx * data->mv_speed * shift,
			data->player.diry * data->mv_speed * shift);
	if (data->key[KS])
		move_maker(data,
			-(data->player.dirx * data->mv_speed * shift),
			-(data->player.diry * data->mv_speed * shift));
	mouse_events(data);
}
