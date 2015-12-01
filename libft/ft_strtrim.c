/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:37:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 10:11:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(*result) * len);
	if (!result)
		return (result);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	start = i;
	i--;
	end = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			end = i + 1;
	if (end - start == 0 || end < start)
		return (malloc(sizeof(char)));
	return (ft_strsub(s, start, end - start));
}
