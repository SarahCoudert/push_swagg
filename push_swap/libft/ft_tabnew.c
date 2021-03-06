/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:42:46 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 18:07:33 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	**ft_tabnew(int size)
{
	char	**res;

	if ((res = malloc(size + 1)) == NULL)
		return (NULL);
	res[size + 1] = NULL;
	return ((void**)res);
}
