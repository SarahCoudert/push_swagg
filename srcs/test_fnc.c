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
		if (ptr->content_size == 1)
			ft_putstr("\t\tP");
		putn();
		ptr = ptr->next;
	}
}

int			check_order(t_list **p, int check)
{
	t_list	*ptr;

	ptr = *p;
	while(ptr->next)
	{
		if (ptr->content > ptr->next->content)
		{
			if (check == 0)
			{
				ft_putstr("\nError, list unsorted\n");
				read_list(*p, "List ");
				return ;
			}
			else
				return (0);
		}
		else
			ptr = ptr->next;
	}
	ft_lstdel(p);
	ft_putchar('\n');
	exit(0);
}