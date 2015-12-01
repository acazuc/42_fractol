/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 07:09:04 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 13:22:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s2[i])
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
		}
		else
			return (-s1[i]);
		i++;
	}
	if (i < n)
	{
		if (s2[i])
			return (s1[i] - s2[i]);
		return (s1[i]);
	}
	return (0);
}
