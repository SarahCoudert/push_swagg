
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		create_list(&a, av, ac);
		push_sort(&a, countelem(a));
	}
	return (0);
}