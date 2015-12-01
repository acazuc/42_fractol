/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:41:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/26 06:33:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_atoi(const char *str)
{
	char	is_neg;
	long	result;
	size_t	i;

	i = 0;
	is_neg = 0;
	while ((str[i] >= 0 && str[i] < 33) || str[i] == 127)
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (result != (int)result)
			return (-1);
		if (str[i] >= '0' && str[i++] <= '9')
			result = result * 10 + str[i - 1] - '0';
		else
			return (is_neg ? -result : result);
	}
	return (is_neg ? -result : result);
}
