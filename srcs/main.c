
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac == 1)
		ft_put_error("Error", 2, -1);
	else
	{
		create_list(&a, av, ac);
	}
	return (0);
}