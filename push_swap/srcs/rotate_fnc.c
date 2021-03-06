/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:37:25 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 17:37:26 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			rotate_a(t_list **a)
{
	int		temp;
	int		content_size_tmp;
	t_list	*alst;

	alst = *a;
	content_size_tmp = alst->content_size;
	temp = alst->content;
	while (alst->next)
	{
		alst->content_size = alst->next->content_size;
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
	alst->content_size = content_size_tmp;
	if (g_bonus.color == 1)
		ft_deferputstr("\033[1;35mra\033[0m ");
	else
		ft_deferputstr("ra ");
	return (1);
}

void		rotate_b(t_list **b)
{
	int		temp;
	int		content_size_tmp;
	t_list	*alst;

	alst = *b;
	content_size_tmp = alst->content_size;
	temp = alst->content;
	while (alst->next)
	{
		alst->content_size = alst->next->content_size;
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
	alst->content_size = content_size_tmp;
	if (g_bonus.color == 1)
		ft_deferputstr("\033[1;32mrb\033[0m ");
	else
		ft_deferputstr("rb ");
}

void		rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
	ft_deferputstr("rr ");
}
