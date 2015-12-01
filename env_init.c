/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 07:02:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 16:49:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx/mlx.h"
#include "window.h"
#include "env.h"

static int	window_init(t_env *env)
{
	if (!(env->window = malloc(sizeof(*(env->window)))))
		return (0);
	env->window->width = 500;
	env->window->height = 500;
	if (!(env->window->mlx = mlx_init()))
		return (0);
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width, env->window->height
					, "acazuc's fract'ol")))
		return (0);
	return (1);
}

static int	position_init(t_env *env)
{
	if (!(env->position = malloc(sizeof(*(env->position)))))
		return (0);
	env->fractal = 3;
	env->position->zoom = 1.;
	env->position->x_offset = 0.;
	env->position->y_offset = 0.;
	env->position->julia_x_factor = 0;
	env->position->julia_y_factor = 0;
	return (1);
}

int			env_init(t_env *env)
{
	env->window = NULL;
	env->position = NULL;
	if (!window_init(env))
		return (0);
	if (!position_init(env))
		return (0);
	return (1);
}
