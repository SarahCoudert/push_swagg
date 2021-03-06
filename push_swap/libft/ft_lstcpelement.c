/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpelement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:05:54 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 18:05:55 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list			*ft_lstcpelement(t_list *copy_from, t_list *copy_to)
{
	t_list		*element;

	element = ft_lstnew(copy_from->content, copy_from->content_size);
	element->next = copy_to;
	return (element);
}
