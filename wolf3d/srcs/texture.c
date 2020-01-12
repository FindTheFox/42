/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:17:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/12 21:01:07 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			sprites_textures(t_wolf *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/wall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/wall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/wall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/wall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/stone.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/ceilling.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
}

void			sprites_textures1(t_wolf *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/capwall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/capwall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/capwall2.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/capwall2.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/capwall.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/capwall2.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
}

void			sprites_textures2(t_wolf *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/mossy.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/redbrick.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/purplestone.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/bluestone.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/colorstone.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/wood.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
}
