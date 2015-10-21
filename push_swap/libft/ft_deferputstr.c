/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deferputstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:05:24 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 18:05:25 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void				ft_deferputstr(char *s)
{
	int				i;
	static char		s_c = 0;

	i = 0;
	while (s[i])
	{
		if (s_c != 0)
			write(1, &s_c, 1);
		s_c = s[i];
		i++;
	}
}
