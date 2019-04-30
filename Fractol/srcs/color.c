/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 01:12:21 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/30 03:35:58 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        colorset0(t_env *e)
{
    static int color[16] = {
        0xffff7d,
		0xffee7d,
		0xffdf7e,
		0xffcf7e,
		0xffbf7e,
		0xffaf7e,
		0xff9f7e,
		0xff8f7f,
		0xfe7e7f,
		0xee6f7f,
		0xde5e7f,
		0xce4f7f,
		0xbe3f7f,
		0xae2f7f,
		0x9d1f7f,
		0x8d0e7f
	};

	e->color = color;
}

void        colorset1(t_env *e)
{
    static int color[16] = {
       0xFF0005,
		0xFD5800,
		0xFCB600,
		0xE3FB00,
		0x85FA00,
		0x27F900,
		0x00F836,
		0x00F791,
		0x01F5EC,
		0x01A2F4,
		0x0147F3,
		0x1501F2,
		0x6E01F1,
		0xC701F0,
		0xEF01BF,
        0xED0166 
    };
    e->color = color;
}

void        colorset2(t_env *e)
{
    static int color[16] = {
        0xf06d89,        
        0xfeaebf,
        0xfbc4d0,
        0xa4ece9,
        0x8fece8,
        0xbeefed,
        0x8fa6ec,
        0xaebeef,
        0xf9cb8a,
        0xf6d19b,
        0xfedfb3,
        0xa39191,
        0xa58d8d,
        0xa17878,
        0xa77070,
    };
    e->color = color;
}