/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 19:45:59 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/06 15:04:01 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_swap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **av, int ac)
{
	int i;
	int ct;

	ct = 1;
	i = 0;
	while (ct <= ac)
	{
		while (++i < ac - ct)
			if (ft_strcmp(av[i], av[i + 1]) > 0)
				ft_swap(&av[i], &av[i + 1]);
		i = 0;
		ct++;
	}
}

int		main(int ac, char **av)
{
	int i;
	int j;

	ft_sort_params(av, ac);
	i = 0;
	while (i++ < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
	}
	return (0);
}
