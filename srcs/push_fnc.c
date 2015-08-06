#include "push_swap.h"

void		push_b(t_list **a, t_list **b)
{
	t_list	*ptr;

	*b = ft_lstcpelement(*a, *b);
	ptr = *a;
	*a = (*a)->next;
	free(ptr);
	if (g_bonus.color == 1)
		ft_deferputstr("\033[1;34mpb\033[0m ");
	else
		ft_deferputstr("pb ");
}

void		push_a(t_list **a, t_list **b)
{
	t_list		*ptr;

	*a = ft_lstcpelement(*b, *a);
	ptr = *b;
	*b = (*b)->next;
	free(ptr);
	if (g_bonus.color == 1)
		ft_deferputstr("\033[1;36mpa\033[0m ");
	else
		ft_deferputstr("pa ");
}
