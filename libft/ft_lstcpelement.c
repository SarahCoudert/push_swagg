#include "includes/libft.h"

/*
 ** copy from est le maillon a copier. copy_to est la liste chainee au debut de laquelle
 ** nous copions copy_from.
 ** element est le nouveau maillon copie depuis copy_from. alst est un pointeur sur le premier maillon
 ** de copy_to.
 **
*/

t_list			*ft_lstcpelement(t_list *copy_from, t_list *copy_to)
{
	t_list		*element;

	element = ft_lstnew(copy_from->content, copy_from->content_size);
	element->next = copy_to;
	return (element);
}
