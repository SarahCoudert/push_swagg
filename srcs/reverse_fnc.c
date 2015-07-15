#include "push_swap.h"

void		reverse_rotate_a(t_list **a)
{
	int		prev;
	int		tmp;
	t_list	*alst;

	alst = *a;
	tmp = 0;
	prev = (*a)->content;
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev;
		prev = tmp;
		alst = alst->next;
	}
	alst = *a;
	alst->content = prev;
	ft_putstr("rra");
}

void		reverse_rotate_b(t_list **b)
{
	int		prev;
	int		tmp;
	t_list	*alst;

	alst = *b;
	tmp = 0;
	prev = (*b)->content;
	while (alst)
	{
		tmp = alst->content;
		alst->content = prev;
		prev = tmp;
		alst = alst->next;
	}
	alst = *b;
	alst->content = prev;
	ft_putstr("rrb");
}

void		rrr(t_list **a, t_list **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	ft_putstr("rrr");
}