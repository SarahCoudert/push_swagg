#include "push_swap.h"

void			swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		medianne(t_list *a, int *size, int nb_rot, int *pivot)
{
	int		*tab;
	int		i;
	t_list *ptr;

	ptr = a;
	i = 0;
	*size = 0;
	while (a && a->content_size != 1 && nb_rot > 0)
	{
		*size = *size + 1;
		a = a->next;
		nb_rot--;
	}
	a = ptr;
	tab = malloc(*size * sizeof(int));
	while (i < *size)
	{
		tab[i] = a->content;
		a = a->next;
		i++;
	}
	a = ptr;
	*pivot = selection_tab(tab, *size);
	free(tab);
}

int			selection_tab(int *tab, int size)
{
	int		i;
	int		min;
	int		where;

	where = 0;
	min = 0;
	i = 0;
	while (where < size)
	{
		while (i < size)
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
	return (tab[(size / 2)]);
}