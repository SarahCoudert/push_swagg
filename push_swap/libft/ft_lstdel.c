/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 13:32:26 by scoudert          #+#    #+#             */
/*   Updated: 2015/06/04 16:18:15 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->next == NULL)
			free(*alst);
		else
		{
			ft_lstdel(&((*alst)->next));
			free(*alst);
		}
	}
}
