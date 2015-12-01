/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:05:20 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 14:59:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	*ft_get_next_split(char *s, char c, int i)
{
	char	*result;
	size_t	j;
	size_t	size;

	j = -1;
	size = 0;
	while (s[i + (++j)] && s[i + j] != c)
		size++;
	result = malloc(sizeof(*result) * (size));
	if (!result)
		return (result);
	j = -1;
	while (s[i + (++j)] && j < size)
		result[j] = s[i + j];
	result[j] = '\0';
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		j;

	count = 1;
	i = -1;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
	result = malloc(sizeof(*result) * (count));
	if (!result)
		return (result);
	i = -1;
	j = -1;
	while (s[++i])
		if ((i == 0 || s[i] == c) && s[i + 1] != c)
			result[++j] = ft_get_next_split((char*)s, c, i == 0 ? i : ++i);
	result[count - 1] = NULL;
	return (result);
}
