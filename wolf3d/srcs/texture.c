/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:17:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/07 19:16:29 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			sprites_textures(t_wolf *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/wall1.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/wall2.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/wall3.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/wall4.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/blueprint.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/ceil.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
	if (!(data->sprite[2].img = SDL_LoadBMP("img/doom.bmp")))
		clean_exit(data, "wolf3d: load_sprites error", 0);
}

void			sprites_textures2(t_wolf *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/metal1.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/metal2.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/metal3.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/metal4.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/bluefloor.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/water.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
	if (!(data->sprite[2].img = SDL_LoadBMP("img/doom.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
}

void			sprites_textures1(t_wolf *data)
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
	if (!(data->sprite[2].img = SDL_LoadBMP("img/doom.bmp")))
		clean_exit(data, "wolf3d: load_sprites error\n", 0);
}
