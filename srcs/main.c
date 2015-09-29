/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:36:42 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:36:44 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_bonus(char **av, int ac)
{
	int	i;

	i = 1;
	g_bonus.color = 0;
	g_bonus.verbose = 0;
	while (i < 4 && i < ac)
	{
		if (ft_strcmp(av[i], "-c") == 0)
		{
			g_bonus.color = 1;
		}
		else if (ft_strcmp(av[i], "-v") == 0)
		{
			g_bonus.verbose = 1;
		}
		else
			return ;
		i++;
	}
}

int		main(int ac, char **av)
{
	t_list	*a;
	int		size;

	size = 0;
	a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		create_bonus(av, ac);
		create_list(&a, av, ac);
		size = countelem(a);
		if (size == 2)
			two_elements(&a);
		if (size == 3)
			three_elements(&a);
		else if (size == 4 || size == 5)
			four_or_five_elements(size, &a);
		else
			push_sort(&a, size, 0, 0);
	}
	check_order(&a, 1);
	ft_putchar('\n');
	return (1);
}
