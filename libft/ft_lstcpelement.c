#include "includes/libft.h"

void	ft_lstcpelement(t_list *copy_from, t_list **copy_to)
{
	t_list		*element;
	t_list		*alst;

	alst = *copy_to;
	element = ft_lstnew(copy_from->content, copy_from->content_size);
	if (copy_to && *copy_to)
	{
		while (alst->next != NULL)
			alst = alst->next;
		if (alst->next == NULL)
			alst->next = element;
	}
	else
	{
		*copy_to = element;
		(*copy_to)->next = NULL;
	}
}
