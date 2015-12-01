/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:13:44 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 09:15:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
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
	if (s2[i])
		return (s1[i] - s2[i]);
	return (s1[i]);
}
