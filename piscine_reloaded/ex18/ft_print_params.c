/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:22:09 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 15:23:04 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			ft_putstr(av[i++]);
			ft_putchar('\n');
		}
	}
	return (0);
}
