#include "push_swap.h"

void		selection(t_list **a, int size)
{
	int		max;
	int		index;
	t_list	*ptr;
	t_list	*b;

	b = NULL;
	ptr = *a;
	index = 0;
	max = ptr->content;
	while (*a)
	{
		while (ptr)
		{
			if (ptr->content > max)
				max = ptr->content;
			ptr = ptr->next;
			index++;
		}
		if (index < size / 2)
			swap_element(a, &b, max, RIGHT);
		else
			swap_element(a, &b, max, LEFT);
		size--;
		ptr = *a;
		if (*a)
			max = (*a)->content;
	}
	get_elements(a, &b);
}

void		swap_element(t_list **a, t_list **b, int max, int way)
{
	while ((*a)->content != max)
	{
		if (way == LEFT)
			reverse_rotate_a(a);
		else
			rotate_a(a);
		ft_putchar(' ');
	}
	if ((*a)->content == max)
	{
		push_b(a, b);
		ft_putchar(' ');	
	}
}

void		get_elements(t_list **a, t_list **b)
{
	t_list *lst;

	lst = *b;
	while (lst)
	{
		read_list(lst, "\nb :D");
		push_a(a, &lst);
	}
}