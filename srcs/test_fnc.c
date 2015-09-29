/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fnc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:46:48 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:46:49 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		read_list(t_list *list, char *name)
{
	t_list	*ptr;
	int		*j;

	j = 0;
	ft_putstr(name);
	ft_putendl("");
	ptr = list;
	while (ptr)
	{
		ft_putnbr(ptr->content);
		ft_putstr("  ");
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

int			check_order(t_list **p, int check)
{
	t_list	*ptr;

	ptr = *p;
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
		{
			if (check == 0)
			{
				ft_putstr("\nError, list unsorted\n");
				read_list(*p, "List ");
				return (1);
			}
			else
				return (0);
		}
		else
			ptr = ptr->next;
	}
	ft_lstdel(p);
	ft_putchar('\n');
	exit(0);
}
