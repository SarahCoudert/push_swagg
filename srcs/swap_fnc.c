#include "push_swap.h"

void		swap_a(t_list *a)
{
	t_list	*ptr;
	int		temp_size;
	int		temp;

	ptr = a;
	temp = ptr->content;
	temp_size = ptr->content_size;
	ptr->content = ptr->next->content;
	ptr->content_size = ptr->next->content_size;
	ptr->next->content = temp;
	ptr->next->content_size = temp_size;
	ft_deferputstr("sa ");
}

void		swap_b(t_list *b)
{
	t_list	*ptr;
	int		temp;
	int		temp_size;

	ptr = b;
	temp = ptr->content;
	temp_size = ptr->content_size;
	ptr->content = ptr->next->content;
	ptr->content_size = ptr->next->content_size;
	ptr->next->content = temp;
	ptr->next->content_size = temp_size;
	ft_deferputstr("sb ");
}

void		ss(t_list *a, t_list *b)
{
	swap_a(a);
	swap_b(b);
	ft_deferputstr("ss ");
}
