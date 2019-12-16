/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by maboye            #+#    #+#             */
/*   Updated: 2019/12/16 19:26:09 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			game_over(t_wolf *data)
{
	play_sound(data, data->sound.PlayerDeath, 5);
	ft_putstr("GAME OVER\n");
}
