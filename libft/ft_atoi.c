
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:02:02 by scoudert          #+#    #+#             */
/*   Updated: 2015/01/09 14:59:46 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_value(int value, int nega, char c)
{
	if (nega == -1 && ((value * nega) * 10) > MAX_INT)
		ft_put_error("Error\n", 2, -1);
	if (nega == 1 && (value * 10) < MIN_INT)
		ft_put_error("Error\n", 2, -1);
	if (nega == 1 && value < MIN_INT / 10 && c > '8')
		ft_put_error("Error\n", 2, -1);
	if (nega == -1 && value > MAX_INT / 10 && c > '7')
		ft_put_error("Error\n", 2, -1);
}

int		ft_atoi(char const *str)
{
	int		is_negative;
	int		value;

	is_negative = -1;
	value = 0;
	str = ft_strtrim(str);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		check_value(value, is_negative, *str);
		value = (value * 10) - (*str - '0');
		str++;
	}
	value *= is_negative;
	return (value);
}
