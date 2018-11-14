/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:52:41 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 02:04:33 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list  *next;
    while (*alst)
    {
        next = (*alst)->next;
        ft_lstdelone(&(*alst), del);
        *alst = next;
    }
}