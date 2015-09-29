/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:05:43 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 18:05:44 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

void	ft_double_tab_del(void **tab)
{
	int	j;

	j = 0;
	if (tab)
	{
		while (tab[j] != NULL)
		{
			free(tab[j]);
			j++;
		}
	}
	free(tab);
}
