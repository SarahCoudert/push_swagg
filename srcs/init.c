/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:09:36 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:09:38 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check(char *s)
{
	int			i;

	i = 0;
	while (ft_isspace(s[i]) != 0)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			ft_put_error("Error", 2, -1);
		i++;
	}
}

void			check_if_swap(t_list **a, int size)
{
	int			pb;
	int			where;
	int			memory;
	t_list		*ptr;
	int			which;

	which = 0;
	ptr = *a;
	memory = 0;
	where = 0;
	pb = 0;
	while (ptr->next)
	{
		where++;
		if (ptr->content > ptr->next->content)
		{
			memory = where;
			which = ptr->content;
			pb++;
		}
		ptr = ptr->next;
	}
	ptr = *a;
	if (pb == 1 && size > 3)
		swap_elements(((memory > size / 2) ? DOWN : UP), a, which);
}

int				check_list(t_list **a)
{
	t_list		*ptr2;
	t_list		*ptr;
	int			temp;

	temp = 0;
	ptr2 = *a;
	ptr = *a;
	ptr2 = *a;
	while (ptr->next)
	{
		ptr->content_size = 0;
		temp = ptr->content;
		while (ptr2->next)
		{
			ptr2 = ptr2->next;
			if (temp == ptr2->content)
				ft_put_error("Error", 2, -1);
		}
		ptr = ptr->next;
		ptr2 = ptr;
	}
	check_if_rotate(a);
	check_if_swap(a, countelem(*a));
	return (1);
}

void			create_list(t_list **lst, char **av, int ac)
{
	int			i;
	int			happend;
	int			j;

	happend = 0;
	j = 0;
	i = 1;
	while (i < ac)
	{
		if ((ft_strcmp(av[i], "-c") != 0 && ft_strcmp(av[i], "-v") != 0)
			|| i > 2)
		{
			happend++;
			check(av[i]);
			j = ft_atoi(av[i]);
			ft_lstaddend(j, 0, lst);
			i++;
		}
		else
			i++;
	}
	if (happend > 0 && check_list(lst))
		check_order(lst, 1);
	else
		exit(0);
}
