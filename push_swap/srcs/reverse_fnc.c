/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_fnc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:37:15 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:37:17 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotate_a(t_list **a)
{
	t_list	*prev;
	int		tmp;
	int		size_tmp;
	t_list	*alst;

	alst = *a;
	tmp = 0;
	prev = (*a);
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev->content;
		prev->content = tmp;
		size_tmp = alst->content_size;
		alst->content_size = prev->content_size;
		prev->content_size = size_tmp;
		alst = alst->next;
	}
	alst = *a;
	alst->content = prev->content;
	if (g_bonus.color == 1)
		ft_deferputstr("\033[1;31mrra\033[0m ");
	else
		ft_deferputstr("rra ");
}

void		reverse_rotate_b(t_list **b)
{
	t_list	*prev;
	int		tmp;
	int		size_tmp;
	t_list	*alst;

	alst = *b;
	tmp = 0;
	prev = (*b);
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev->content;
		prev->content = tmp;
		size_tmp = alst->content_size;
		alst->content_size = prev->content_size;
		prev->content_size = size_tmp;
		alst = alst->next;
	}
	alst = *b;
	alst->content = prev->content;
	ft_deferputstr("rrb ");
}

void		rrr(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	ft_deferputstr("rrr ");
}
