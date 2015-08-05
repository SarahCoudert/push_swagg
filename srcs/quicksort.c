#include "push_swap.h"

/*
 ** trouver la medianne ==> la definir comme pivot. Tout ce qui est plus petit est rra, et ce qui est plus grand est push b
 **
*/

void		order_list(t_list **a, int element_b, int *nb_rot)
{
	while ((*a) && element_b > 0)
	{
		rotate_a(a);
		element_b--;
		*nb_rot = *nb_rot - 1;
	}
}

void		get_elements(t_list **a, t_list **b, int pivot)
{
	t_list *lst;

	lst = *b;
	while (lst)
	{
		if (lst->content == pivot && lst->next != NULL)
			rotate_b(b);
		else
			push_a(a, b);
		lst = *b;
	}
}

void		ft_quicksort(t_list **a, int pivot, int size, int *nb_rot)
{
	t_list			*ptr;
	t_list			*b;
	int				element_b;

	element_b = 0;
	b = NULL;
	ptr = *a;
	while (*a && size > 0)
	{
		if (ptr->content == pivot)
		{
			ptr->content_size = 1;
			element_b++;
			push_b(a, &b);
		}
		else if (ptr->content_size == 1 && ptr->content != pivot)
			break ;
		else if (ptr->content > pivot)
		{
			push_b(a, &b);
			element_b++;
		}
		else if (ptr->content < pivot)
		{
			rotate_a(a);
			*nb_rot = *nb_rot - 1;
		}
		ptr = *a;
		size--;
	}
	get_elements(a, &b, pivot);
	order_list(a, element_b, nb_rot);
}

void		push_sort(t_list **a, int lst_size)
{
	int		pivot;
	int		nb_pivot;
	int		size;
	int		nb_rotate;

	nb_rotate = lst_size;
	size = 0;
	pivot = 0;
	nb_pivot = 0;
	while (nb_pivot < lst_size)
	{
		while (*a && (*a)->content_size == 1)
		{
			rotate_a(a);
			nb_rotate--;
			if (nb_rotate == 0)
				nb_rotate = lst_size;
		}
		check_order(*a, 1);
		pivot = medianne(*a, &size, nb_rotate);
		nb_pivot++;
		ft_quicksort(a, pivot, size, &nb_rotate);
		if (nb_rotate == 0)
			nb_rotate = lst_size;
	}
	while (nb_rotate > 0)
	{
		rotate_a(a);
		nb_rotate--;
	}
}
