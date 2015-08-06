
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*a;
	int		size;

	size = 0;
	a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		create_list(&a, av, ac);
		size = countelem(a);
		if (size == 2)
			two_elements(&a);
		if (size == 3)
			three_elements(&a);
		else if (size == 4 || size == 5)
			four_or_five_elements(size, &a);
		else
			push_sort(&a, size, 0, 0);
	}
	check_order(&a, 1);
	ft_putchar('\n');
	return (1);
}