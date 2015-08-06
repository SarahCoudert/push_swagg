#include "push_swap.h"

void		push_b(t_list **a, t_list **b)
{
	t_list	*ptr;

	*b = ft_lstcpelement(*a, *b);
	ptr = *a;
	*a = (*a)->next;
	free(ptr);
	ft_deferputstr("pb ");
}

void		push_a(t_list **a, t_list **b)
{
	t_list		*ptr;

	*a = ft_lstcpelement(*b, *a);
	ptr = *b;
	*b = (*b)->next;
	free(ptr);
	ft_deferputstr("pa ");
}
