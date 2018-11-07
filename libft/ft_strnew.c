/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:06 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/07 17:59:40 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	int i;

	if (!(str = (char *)malloc(sizeof(size_t) * size)))
		return (NULL);
	i = 0;
	while (str[i])
		str[i++] = '\0';
	return (str);
}
