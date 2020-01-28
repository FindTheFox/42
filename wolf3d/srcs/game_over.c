/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/28 18:52:31 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			game_over(t_wolf *data)
{
	//play_sound(data, data->sound.playerdeath, 5);
	(void)data;
	ft_putstr("GAME OVER\n");
}
