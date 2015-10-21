/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unusual_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:47:27 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:47:29 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_if_rotate(t_list **a)
{
	min_rotate(a);
	max_rotate(a, 0);
}

void		min_rotate(t_list **a)
{
	int		min;
	t_list	*ptr;
	int		pb;

	pb = 0;
	ptr = *a;
	min = 0;
	min = min_lst(*a);
	while (ptr->next && ptr->next->content != min)
	{
		if (ptr->content > ptr->next->content)
			pb++;
		ptr = ptr->next;
	}
	if (ptr->next && ptr->next->content == min && ptr->next->next == NULL &&
		pb == 0)
	{
		reverse_rotate_a(a);
		if (g_bonus.verbose == 1)
			read_list(*a, "");
		putn();
		exit(0);
	}
}

void		max_rotate(t_list **a, int pb)
{
	int		max;
	t_list	*ptr;
	int		prev;

	prev = ptr->content;
	ptr = *a;
	max = ptr->content;
	while (ptr)
	{
		if (ptr->content > max)
			max = ptr->content;
		if (prev > ptr->content)
			pb++;
		prev = ptr->content;
		ptr = ptr->next;
	}
	if ((*a)->content == max && pb == 1)
	{
		rotate_a(a);
		if (g_bonus.verbose == 1)
			read_list(*a, "");
		putn();
		exit(0);
	}
}
