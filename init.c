#include "push_swap.h"

void			check(char *s)
{
	int		i;

	i = 0;
	while (ft_isspace(s[i]) != 0)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while(s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			ft_put_error("Error", 2, -1);
		i++;
	}
}

#include <stdio.h>

void			check_list(t_list **a)
{
	t_list		*ptr2;
	t_list		*ptr;
	int			temp;

	temp = 0;
	ptr2 = *a;
	ptr = *a;
	ptr2 = *a;
	while (ptr->next)
	{
		temp = ptr->content;
		while (ptr2->next)
		{
			ptr2 = ptr2->next;
			if (temp == ptr2->content)
				ft_put_error("Error", 2, -1);
		}
		ptr = ptr->next;
		ptr2 = ptr;
	}
}

void			create_list(t_list **lst, char **av, int ac)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < ac)
	{
		check(av[i]);
		j = ft_atoi(av[i]);
		ft_lstaddend(j, sizeof(int), lst);
		i++;
	}
	check_list(lst);
}