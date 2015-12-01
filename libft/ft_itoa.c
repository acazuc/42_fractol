/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:38:01 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 15:02:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_size(int n)
{
	int		size;
	int		i;

	size = n < 0 ? 2 : 1;
	n = n < 0 ? -n : n;
	i = 1;
	while (n / i > 0)
	{
		size++;
		i = i * 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*result;
	size_t	size;
	size_t	j;
	size_t	i;
	size_t	nb;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	nb = n < 0 ? -n : n;
	size = get_size(n);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	result[size - 1] = '\0';
	if (n < 0)
		result[0] = '-';
	j = 1;
	i = 1;
	while (nb / j > 0)
	{
		result[size - i++ - 1] = (nb / j) % 10 + '0';
		j = j * 10;
	}
	return (result);
}
