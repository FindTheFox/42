/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by maboye            #+#    #+#             */
/*   Updated: 2019/12/10 16:39:11 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		get_objangle(t_wolf *data, t_object *list)
{
	float	spritex;
	float	spritey;

	list->data.dst_fromplayer = distance_calc(data->player.x, data->player.y,
		list->x, list->y);
	spritex = list->x - data->player.x;
	spritey = list->y - data->player.y;
	
	list->data.mid = (0.5 * (data->player.dirx
		/ (data->player.fov / 2)) + 0.5) * W_WIDTH;
	printf("%f\n", list->data.mid);
	
	list->data.invDet = 1.0 / ((data->player.planex * data->player.diry) - (data->player.dirx * data->player.planey)); 
	list->data.transformx = list->data.invDet * (data->player.diry * spritex - data->player.dirx * spritey);
	list->data.transformy = list->data.invDet * (-data->player.planey * spritex + data->player.planex * spritey);

	list->data.spriteScreenX = (int)((W_WIDTH / 2) * (1 + list->data.transformx / list->data.transformy));
	
	list->data.spriteHeight = abs((int)(W_HEIGHT / (list->data.transformy)));
	list->data.drawStartY = -list->data.spriteHeight / 2 + W_HEIGHT / 2;
	if (list->data.drawStartY < 0)
		list->data.drawStartY = 0;
	list->data.drawEndY = list->data.spriteHeight / 2 + W_HEIGHT / 2;
	if (list->data.drawEndY >= W_HEIGHT)
		list->data.drawEndY = W_HEIGHT - 1;

	list->data.spriteWidth = abs((int)(W_HEIGHT / list->data.transformy));
	list->data.drawStartX = -list->data.spriteWidth / 2 + list->data.spriteScreenX;
	if (list->data.drawStartX < 0)
		list->data.drawStartX = 0;
	list->data.drawEndX = list->data.spriteWidth / 2 + list->data.spriteScreenX;
	if (list->data.drawEndX >= W_WIDTH)
		list->data.drawEndX = W_WIDTH - 1; 
}

static void		display_object(t_wolf *d, t_object *l)
{
	int			sx;
	int			sy;
	int			p;
	int			texY;
	int			texX;
	uint32_t	pixel;

	sx = l->data.drawStartX;
	while (sx < l->data.drawEndX)
	{
		texX = (int)(256 * (sx - (-((int)l->data.spriteWidth) / 2 + l->data.spriteScreenX))
			* l->sprite.img->w / l->data.spriteWidth) / 256; 
		if (l->data.transformy > 0 && sx > 0 && sx < W_WIDTH && l->data.transformy < d->map.depth_buffer[sx])
		{
			sy = l->data.drawStartY;
			while (sy < l->data.drawEndY)
			{
				p = (sy) * 256 - W_HEIGHT * 128 + l->data.spriteHeight * 128;
				texY = ((p * l->sprite.img->h) / l->data.spriteHeight) / 256;
				pixel = get_pixel_obj(l, l->si, texX, texY);
				if (pixel != l->data.zpixel)
					put_pixel(d->screen, sx, sy, pixel);
				d->map.depth_buffer[sx] = l->data.dst_fromplayer;
				sy++;
			}
		}
		sx++;
	}
}

void			objects(t_wolf *data, t_object *list)
{
	t_object	*head;

	head = list;
	if (list == NULL)
		return ;
	while (list)
	{
		list->data.zpixel = get_pixel(data, list->si, 0, 0);
		if (list->type > 2 && list->type < 10)
		{
			list->i = (int)list->x + data->map.width * (int)list->y;
			get_objangle(data, list);
			display_object(data, list);
		}
		list = list->next;
	}
	list = head;
}
