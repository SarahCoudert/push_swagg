#include "push_swap.h"

void		selection(t_list **a, int size)
{
	int		min;
	int		index;
	t_list	*ptr;
	t_list	*b;

	b = NULL;
	ptr = *a;
	index = 0;
	min = ptr->content;
	while (*a)
	{
		while (ptr)
		{
			if (ptr->content < min)
				min = ptr->content;
			ptr = ptr->next;
			index++;
		}
		if (index < size / 2)
			swap_element(a, &b, min, RIGHT);
		else
			swap_element(a, &b, min, LEFT);
		size--;
		ptr = *a;
		if (*a)
			min = (*a)->content;
	}
	get_elements(a, &b);
}

void		swap_element(t_list **a, t_list **b, int min, int way)
{
	while ((*a)->content != min)
	{
		if (way == LEFT)
			reverse_rotate_a(a);
		else
			rotate_a(a);
		ft_putchar(' ');
	}
	if ((*a)->content == min)
	{
		push_b(a, b);
		ft_putchar(' ');
	}
}

void		get_elements(t_list **a, t_list **b)
{
	t_list *lst;

	lst = *b;
	while (lst->next)
	{
		push_a(a, &lst);
		ft_putchar(' ');
	}
		push_a(a, &lst);
		ft_putchar('\n');
}