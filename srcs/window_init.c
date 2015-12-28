/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:21:18 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 09:00:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*window_init(void)
{
	t_window	*window;

	if (!(window = malloc(sizeof(*window))))
		return (NULL);
	window->width = 1920;
	window->height = 1080;
	if (!(window->mlx = mlx_init()))
	{
		free(window);
		return (NULL);
	}
	if (!(window->mlx_window = mlx_new_window(window->mlx, window->width
					, window->height, "acazuc's fract'ol")))
	{
		free(window);
		return (NULL);
	}
	return (window);
}
