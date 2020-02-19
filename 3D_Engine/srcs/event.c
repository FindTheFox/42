/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:31:07 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/19 20:22:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/3d_engine.h"

static void         move_events(t_env *e)
{
    if (e->event.key.keysym.sym == SDLK_z)
        e->key[W] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_s)
        e->key[S] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_q)
        e->key[A] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_d)
        e->key[D] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_a)
        e->key[Q] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_e)
        e->key[E] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_UP)
        e->key[UP] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.sym == SDLK_DOWN)
        e->key[DOWN] = e->event.type == SDL_KEYDOWN ? 1 : 0;
}

static void         deal_move_event(t_env *e)
{
    if (e->key[UP] || e->key[DOWN])
    {
        e->vlist.forward = vectormult(e->vlist.lookdir, 8.0 * e->theta);
        if (e->key[UP])
            e->vlist.vcamera = vectoradd(e->vlist.vcamera, e->vlist.forward);
        else if (e->key[DOWN])
            e->vlist.vcamera = vectorsub(e->vlist.vcamera, e->vlist.forward);
    }
    if (e->key[W])
        e->vlist.vcamera.y += 8.0 * e->theta;
    if (e->key[S])
        e->vlist.vcamera.y -= 8.0 * e->theta;
    if (e->key[A])
        e->vlist.vcamera.x += 8.0 * e->theta;
    if (e->key[D])
        e->vlist.vcamera.x -= 8.0 * e->theta;
    if (e->key[Q])
    {
        e->yaw -= 2.0 * e->theta;
        //init_matrix_roty(&e->mlist.camroty, e->yaw);
    }
    if (e->key[E])
    {
        e->yaw += 2.0 * e->theta;
        //init_matrix_roty(&e->mlist.camroty, e->yaw);    
    }
}

void                event(t_env *env)
{
    while (SDL_PollEvent(&env->event))
    {
        if ((env->event.key.keysym.sym == SDLK_ESCAPE
		&& env->event.type == SDL_KEYDOWN)
		|| env->event.type == SDL_QUIT)
            ft_exit(env, "fini\n", 1);
        move_events(env);
    }
    deal_move_event(env);
}
