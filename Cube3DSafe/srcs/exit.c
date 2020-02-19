/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:28:52 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/13 02:29:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void        ft_exit(t_env *env, char *s, int flag)
{
    if (env->rend)
        SDL_DestroyRenderer(env->rend);
    if (env->window)
        SDL_DestroyWindow(env->window);
    SDL_Quit();
    if (s)
        ft_putstr_fd(s, 2);
    exit(flag == 1 ? EXIT_SUCCESS : EXIT_FAILURE);
}
