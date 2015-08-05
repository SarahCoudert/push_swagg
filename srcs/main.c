
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	size = 0;
	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		create_list(&a, av, ac);
		size = countelem(a);
		if (size == 3)
			three_elements(&a);
		else
			push_sort(&a, size);
	}
	return (0);
}