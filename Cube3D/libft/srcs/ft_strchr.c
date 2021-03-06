/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:27 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/08 18:26:19 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] || (s[i] == '\0' && c == '\0'))
	{
		if (s[i] == (unsigned char)c)
			return (&(((char*)s)[i]));
		i++;
	}
	return (0);
}
