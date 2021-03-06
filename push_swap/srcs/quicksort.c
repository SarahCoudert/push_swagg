/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:36:59 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:37:04 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		order_list(t_list **a, int element_b, int *nb_rot)
{
	while ((*a) && element_b > 0)
	{
		rotate_a(a);
		element_b--;
		*nb_rot = *nb_rot - 1;
	}
	if (g_bonus.verbose == 1)
		read_list(*a, "\n");
}

void		get_elements(t_list **a, t_list **b, int pivot)
{
	t_list *lst;

	lst = *b;
	while (lst)
	{
		if (lst->content == pivot && lst->next != NULL)
			rotate_b(b);
		else
			push_a(a, b);
		lst = *b;
	}
}

void		ft_quicksort(t_list **a, int pivot, int size, int *nb_rot)
{
	t_list			*b;
	int				element_b;

	element_b = 0;
	b = NULL;
	while (*a && size > 0)
	{
		if ((*a)->content == pivot)
		{
			(*a)->content_size = 1;
			element_b++;
			push_b(a, &b);
		}
		else if ((*a)->content > pivot)
		{
			push_b(a, &b);
			element_b++;
		}
		else if ((*a)->content < pivot && (*nb_rot = *nb_rot - 1))
			rotate_a(a);
		size--;
	}
	get_elements(a, &b, pivot);
	order_list(a, element_b, nb_rot);
}

void		push_sort(t_list **a, int lst_size, int size, int pivot)
{
	int		nb_pivot;
	int		nb_rotate;

	nb_rotate = lst_size;
	nb_pivot = 0;
	while (nb_pivot < lst_size)
	{
		while (*a && (*a)->content_size == 1 && (rotate_a(a)))
		{
			nb_rotate--;
			if (nb_rotate == 0)
				nb_rotate = lst_size;
		}
		check_order(a, 1);
		medianne(*a, &size, nb_rotate, &pivot);
		nb_pivot++;
		ft_quicksort(a, pivot, size, &nb_rotate);
		if (nb_rotate == 0)
			nb_rotate = lst_size;
	}
	while (nb_rotate > 0)
	{
		rotate_a(a);
		nb_rotate--;
	}
}
