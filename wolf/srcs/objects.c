/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by maboye            #+#    #+#             */
/*   Updated: 2019/12/07 17:51:26 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		get_objdata(t_wolf *data, t_object *list)
{
	list->data.ceiling = (float)(W_HEIGHT / 2)
		- W_HEIGHT / list->data.dst_fromplayer;
	list->data.floor = W_HEIGHT - list->data.ceiling;
	list->data.height = list->data.floor - list->data.ceiling;
	list->data.ratio = (float)list->sprite.img->h
		/ (float)list->sprite.img->w;
	list->data.width = list->data.height / list->data.ratio;
	list->data.mid = (0.5 * (list->data.angle
		/ (data->player.fov / 2)) + 0.5) * W_WIDTH;
}

static void		get_objangle(t_wolf *data, t_object *list)
{
	float	spritex;
	float	spritey;

	list->data.dst_fromplayer = distance(data->player.x, data->player.y,
		list->x, list->y);
	spritex = list->x - data->player.x;
	spritey = list->y - data->player.y;
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
	if (list->data.drawEndX >= W_WIDTH)
		list->data.drawEndX = W_WIDTH - 1; 
 	/*list->data.angle = atan2f(eyex, eyey)
		- atan2f(list->x - data->player.x, list->y - data->player.y);
	if (list->data.angle < -3.114159)
		list->data.angle += 2 * 3.14159;
	else if (list->data.angle > 3.14159)
		list->data.angle -= 2 * 3.14159;
	*/
}

static void		put_objpixel(t_wolf *data, t_object *list, float sy)
{
	uint32_t	pixel;

	if (list->data.column < 0 || list->data.column > W_WIDTH)
		return ;
	if (data->map.depth_buffer[list->data.column]
			< list->data.dst_fromplayer)
		return ;
	pixel = get_pixel(data, list->si,
			list->data.samplex, list->data.sampley);
	if (pixel == list->data.zpixel)
		return ;
	put_pixel(data->screen,
			list->data.column,
			list->data.ceiling + sy, pixel);
	data->map.depth_buffer[list->data.column] = list->data.dst_fromplayer;
}

static void		display_object(t_wolf *d, t_object *l)
{
	int		sx;
	int		sy;
	int		p;
	int		texY;
	int		texX;

	//l->data.zpixel = get_pixel(d, list->si, 0, 0);
	/*tx = 1 / list->data.width;
	ty = 1 / list->data.height;
	tmp = list->data.width / 2;*/
	sx = l->data.drawStartX;
	while (sx < l->data.drawEndX)
	{
		texX = (int)(256 * (sx - (-l->data.spriteWidth / 2 + l->data.spriteScreenX))
			* l->sprite.img->w / l->data.spriteWidth) / 256; 
		if (l->data.transformy > 0 && sx > 0 && sx < W_WIDTH && l->data.transformy < d->map.depth_buffer[sx])
		{
			sy = l->data.drawStartY;
			while (sy < l->data.drawEndY)
			{
				p = (sy) * 256 - W_HEIGHT * 128 + l->data.spriteHeight * 128;
				texY = ((p * l->sprite.img->h) / l->data.spriteHeight) / 256;
				//put_objpixel(data, list, sy);
        		put_pixel(d->screen, sx, sy, get_pixel_obj(l, l->si, texX, texY));
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
		if (list->type > 2 && list->type < 10)
		{
			//list->i = (int)list->x + data->map.width * (int)list->y;
			if (list->type < 4)
				object_actions(data, list);
			get_objangle(data, list);
			//if (/*fabs(list->data.angle) < data->player.fov / 2
			//		&&*/ list->data.dst_fromplayer > 1
			//		&& list->data.dst_fromplayer < data->map.depth)
			//{
				//get_objdata(data, list);
				display_object(data, list);
			//}
		}
		list = list->next;
	}
	list = head;
}
