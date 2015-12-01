/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:55:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/24 14:02:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	ret = malloc(sizeof(*ret) * size);
	if (!ret)
		return (ret);
	i = 0;
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
