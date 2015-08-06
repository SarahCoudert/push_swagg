/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:36:58 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/18 11:28:33 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	ft_strtrim(char *s)
{
	int	offset;
	int	i;

	offset = 0;
	i = 0;
	while (*s && ft_isspace(s[offset]))
		offset++;
	if (offset != 0)
	{
		while (s[offset + i - 1])
			s[i] = s[offset + i];
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_isspace(s[i]))
		s[i] = '\0';
		i--;
	}
}