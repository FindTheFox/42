/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:01:11 by saneveu           #+#    #+#             */
/*   Updated: 2019/02/21 22:06:13 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	deal_key(int key, t_env *e)
{
    key == 65307 ? end_program(e) : 0;
    key == 114 ? reset(e) : 0;
    key == 65363 ? rotate(e, &e->rot_x, SPEED_ROT) : 0;	
    key == 65361 ? rotate(e, &e->rot_x, -SPEED_ROT) : 0;	
    return (0);
}
