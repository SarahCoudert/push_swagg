#include "push_swap.h"

/*
 ** trouver la medianne ==> la definir comme pivot. Tout ce qui est plus petit est rra, et ce qui est plus grand est push b
 **
*/

void		order_list(t_list **a, int size)
{
	t_list *ptr;

	ptr = *a;
	while ((*a)->content_size != 1 && size > 0)
	{
		rotate_a(a);
		ft_putchar(' ');
		size--;
	}
	*a = ptr;
}

void		get_elements(t_list **a, t_list **b, int pivot)
{
	t_list *lst;
	int		find_pivot;

	find_pivot = 0;
	lst = *b;
	while (lst)
	{
		if (lst->content == pivot && find_pivot == 0)
		{
			rotate_b(b);
			find_pivot = 1;
		}
		else
			push_a(a, &lst);
		ft_putchar(' ');
	}
}

void		ft_quicksort(t_list **a, int pivot, int size)
{
	t_list	*ptr;
	t_list	*b;
	int		nb_rotate;

	nb_rotate = size;
	b = NULL;
	ptr = *a;
	while (ptr && (ptr->content_size != 1 && ptr->content != pivot))
	{
		if (ptr->content == pivot)
		{
			ptr->content_size = 1;
			push_b(a, &b);
		}
		else if (ptr->content > pivot)
			push_b(a, &b);
		else if (ptr->content < pivot)
		{
			rotate_a(a);
			nb_rotate--;
		}
		read_list(*a, "coeur");
		ft_putchar(' ');
	}
	read_list(b, "list b, chiffres superieur au pivot et pivot");
	read_list(*a, "list a inferieur au pivot");
	get_elements(a, &b, pivot);
	order_list(a, nb_rotate);
}

void		push_sort(t_list **a, int size)
{
	int	pivot;
	int	nb_pivot;

	pivot = 0;
	nb_pivot = 0;
	while (nb_pivot < size)
	{
		pivot = medianne(*a);
		nb_pivot++;
				#include <stdio.h>
		printf("pivot : %d\tsize : %d\n", pivot, size);
		ft_quicksort(a, pivot, size);
		read_list(*a, "\nlist a after first quick sort");
		return ;
	}
}
