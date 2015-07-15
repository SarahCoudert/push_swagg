#include "push_swap.h"

void		selection(t_list **a, int size)
{
	int		min;
	int		index;
	t_list	*ptr;
	t_list	*ptr_index;

	ptr_index = *a;
	ptr = *a;
	index = 0;
	min = ptr->content;
	while (ptr)
	{
		while (ptr_index)
		{
			if (ptr_index->content < min)
				min = ptr_index->content;
			ptr_index = ptr_index->next;
			index++;
		}
		if (index < size / 2)
			swap_element(a, ptr->content, min, RIGHT);
		else
			swap_element(a, ptr->content, min, LEFT);
		ptr = ptr->next;
		ptr_index = ptr;
		if (ptr_index)
			min = ptr->content;
	}
	read_list(*a, "\nfinal list");
}

void		swap_element(t_list **a, int begin, int min, int way)
{
	t_list	*b;

	b = NULL;
	if (begin == min)
		return ;
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
		push_b(a, &b);
		ft_putchar(' ');	
	}
	while ((*a)->content != begin)
	{
		if (way == LEFT)
		{
			rotate_a(a);
		}
		else
		{
			reverse_rotate_a(a);
		}
		ft_putchar(' ');
	}
	if ((*a)->content == begin)
	{
		push_a(a, &b);
		ft_putchar(' ');
	}
}