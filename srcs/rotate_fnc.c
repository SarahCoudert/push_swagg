#include "push_swap.h"

void		rotate_a(t_list **a)
{
	int		temp;
	t_list	*alst;

	alst = *a;
	temp = alst->content;
	while (alst->next)
	{
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
	ft_putstr("ra");
}


void		rotate_b(t_list **b)
{
	int		temp;
	t_list	*alst;

	alst = *b;
	temp = alst->content;
	while (alst->next)
	{
		alst->content = alst->next->content;
		alst = alst->next;
	}
	alst->content = temp;
	ft_putstr("rb");
}

void		rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
	ft_putstr("rr");
}