#include "push_swap.h"

void		push_b(t_list **a, t_list **b)
{
	t_list	*ptr;

	ptr = *a;
	*b = ft_lstcpelement(*a, *b);
	*a = (*a)->next;
	free(ptr);
	ft_deferputstr("pb ");
}

void		push_a(t_list **a, t_list **b)
{
	t_list		*ptr;

	ptr = *b;
	*a = ft_lstcpelement(*b, *a);
	*b = (*b)->next;
	free(ptr);
	ft_deferputstr("pa ");
}
