/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:33:16 by bebosson          #+#    #+#             */
/*   Updated: 2020/01/12 17:49:25 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

SDL_Color			ft_hex_to_rgb(int hexa)
{
	SDL_Color color;

	color.r = hexa >> 24;
	color.g = hexa >> 16;
	color.b = hexa >> 8;
	color.a = 0xff;;
	return (color);
}

static int			move_cursor(t_wolf *data, int *cursor)
{
	if (data->event.key.keysym.sym == SDLK_UP && *cursor > 1)
	{
		//play_sound(data, data->sound.tic, 5);
		return (--*cursor);
	}
	else if (data->event.key.keysym.sym == SDLK_DOWN && *cursor < 2)
	{
		//play_sound(data, data->sound.tic, 5);
		return (++*cursor);
	}
	else
		return (*cursor);
}

static void			draw_cursor(t_wolf *data, int cursor)
{
	int			x;

	x = 7;
	(*(data->rect)) = (SDL_Rect){x * (W_WIDTH / 16), (6 + cursor)
		* (W_HEIGHT / 10), (W_WIDTH / 16) / 2, (W_HEIGHT / 10) / 2};
	set_rect_to_screen(data, data->rect, 0xdf2727);
}

static void			draw_main_rect(t_wolf *data, int cursor)
{
	SDL_Texture *font;

	(*(data->rect)) = (SDL_Rect){0, 0, W_WIDTH, W_HEIGHT};
	font = SDL_CreateTextureFromSurface(data->renderer, data->sprite[2].img);
	SDL_RenderCopy(data->renderer, font, NULL, data->rect);
	(*(data->rect)) = (SDL_Rect){W_WIDTH / 3, W_HEIGHT / 4, 0, 0};
	data->policep = data->police;
	set_write_to_screen(data, (*(data->rect)), 0xffffff, "ASYLUM");
	(*(data->rect)) = (SDL_Rect){2 * (W_WIDTH / 16), 7 * (W_HEIGHT / 10), 2
		* (W_WIDTH / 16), 0.75 * (W_HEIGHT / 10)};
	data->policep = data->police2;
	set_write_to_screen(data, (*(data->rect)), 0xffffff, "PLAY");
	(*(data->rect)) = (SDL_Rect){2 * (W_WIDTH / 16), 8 * (W_HEIGHT / 10), 2
		* (W_WIDTH / 16), 0.75 * (W_HEIGHT / 10)};
	set_write_to_screen(data, (*(data->rect)), 0xffffff, "QUIT");
	draw_cursor(data, cursor);
	SDL_RenderPresent(data->renderer);
	SDL_DestroyTexture(font);
}

void				w_pause(t_wolf *data)
{
	int	cursor;

	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_MOUSEMOTION);
	cursor = 1;
	draw_main_rect(data, cursor);
	//play_music(data, data->sound.pausemusic);
	while (data->key[KP])
	{
		SDL_PollEvent(&data->event);
		if ((data->event.key.keysym.sym == SDLK_SPACE && cursor == 1)
		|| (data->event.key.keysym.sym == SDLK_p
		&& data->event.type == SDL_KEYDOWN))
			help_pause(data);
		else if ((data->event.key.keysym.sym == SDLK_SPACE && cursor == 2)
			|| data->event.window.event == SDL_WINDOWEVENT_CLOSE
			|| data->event.key.keysym.sym == SDLK_ESCAPE)
			clean_exit(data, NULL, 1);
		else if (data->event.key.keysym.sym == SDLK_UP
				|| data->event.key.keysym.sym == SDLK_DOWN)
		{
			cursor = move_cursor(data, &cursor);
			draw_main_rect(data, cursor);
		}
	}
}
