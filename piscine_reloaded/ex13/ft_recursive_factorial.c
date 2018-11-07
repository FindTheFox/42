/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:00:24 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 14:36:56 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}
