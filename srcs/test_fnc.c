#include "push_swap.h"

void		read_list(t_list *list, char *name)
{
	t_list	*ptr;
	int		*j;

	j = 0;
	ft_putstr(name);
	ft_putendl("");
	ptr  = list;
	while (ptr)
	{
		ft_putstr("\t");
		ft_putnbr(ptr->content);
		putn();
		ptr = ptr->next;
	}
}