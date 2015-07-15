#include "push_swap.h"

void		swap_a(t_list *a)
{
	t_list	*ptr;
	int		temp;

	ptr = a;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
	ft_putstr("sa");
}

void		swap_b(t_list *b)
{
	t_list	*ptr;
	int		temp;

	ptr = b;
	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
	ft_putstr("sb");
}

void		ss(t_list *a, t_list *b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr("ss");
}
