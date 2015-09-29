/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deferputchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 18:04:56 by scoudert          #+#    #+#             */
/*   Updated: 2015/09/29 18:05:15 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_deferputchar(char c)
{
	static char	s_c = 0;

	if (s_c != 0)
		write(1, &s_c, 1);
	s_c = c;
}
