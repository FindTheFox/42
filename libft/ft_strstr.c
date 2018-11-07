/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:23:14 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/07 17:59:40 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
