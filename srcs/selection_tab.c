#include "push_swap.h"

int			medianne(t_list *a)
{
	int		*tab;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (a->content_size != 1 && a)
	{
		size++;
		a = a->next;
	}
	tab = malloc(size);
	while (i < size)
	{
		tab[i] = a->content;
	}
	tab = selection_tab(tab, size);
	return (tab[size / 2]);
}

int			*selection_tab(int *tab, int size)
{
	int		i;
	int		min;
	int		where;
	int		temp;

	temp = 0;
	where = 0;
	min = 0;
	i = 0;
	while (where != size)
	{
		while (i != size)
		{
			if (tab[i] < tab[min])
				min = i;
			i++;
		}
		swap(&tab[where], &tab[min]);
		where++;
		i = where;
		min = where;
	}
	return (tab);
}