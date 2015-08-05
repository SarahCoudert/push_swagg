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
	else
	{
		swap_a(*lst);
		reverse_rotate_a(lst);
	}
	ft_putchar('\n');
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
	ft_putchar('\n');
	exit(0);
}