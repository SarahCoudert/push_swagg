#include "includes/libft.h"

/*
 ** copy_from is the element to copy
 ** we copy copy_from to the begin of copy_to
 ** element is the new element that we copied from copy_from
 **
*/

t_list			*ft_lstcpelement(t_list *copy_from, t_list *copy_to)
{
	t_list		*element;

	element = ft_lstnew(copy_from->content, copy_from->content_size);
	element->next = copy_to;
	return (element);
}
