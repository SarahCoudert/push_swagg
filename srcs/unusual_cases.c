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

void		three_elements(t_list **lst)
{
	int		a;
	int		b;
	int		c;

	a = (*lst)->content;
	b = (*lst)->next->content;
	c = (*lst)->next->next->content;
	if (a < b && a < c && b > c)
	{
		reverse_rotate_a(lst);
		swap_a(*lst);
	}
	else if (a < b && a > c && b > c)
		reverse_rotate_a(lst);
	else if (a > b && a < c && b < c)
		swap_a(*lst);
	else if (a > b && a > c && b < c)
		rotate_a(lst);
	else if (a > b && b > c && a > c)
	{
		swap_a(*lst);
		reverse_rotate_a(lst);
	}
}

int			min_lst(t_list *a)
{
	int		min;

	min = a->content;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

void		swap_elements(int way, t_list **a, int pb)
{
	int		continu;
	int		begin;

	begin = min_lst(*a);
	continu = 1;
	while (continu)
	{
		if ((*a)->content == pb)
		{
			swap_a(*a);
			continu = 0;
		}
		if (way == UP && continu == 1)
			rotate_a(a);
		else if (way == DOWN && continu == 1)
			reverse_rotate_a(a);
	}
	while ((*a)->content != begin)
	{
		if (way == UP)
			reverse_rotate_a(a);
		else if (way == DOWN)
			rotate_a(a);
	}
}

void		two_elements(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(*a);
}

void		four_or_five_elements(int size, t_list **a)
{
	t_list	*b;
	int		i;

	i = 0;
	b = NULL;
	push_b(a, &b);
	push_b(a, &b);
	if (size == 4)
		two_elements(a);
	else
		three_elements(a);
	two_elements(&b);
	while (i < size)
	{
		if (b && (b->content < (*a)->content || size - i == countelem(b)))
			push_a(a, &b);
		else
		{
			rotate_a(a);
			i++;
		}
	}
}
