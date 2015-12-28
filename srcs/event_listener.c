/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:21:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 09:02:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_position(t_env *env)
{
	if (env->position->zoom < 1)
		env->position->zoom = 1;
	if (env->position->x_offset < 0)
		env->position->x_offset = 0;
	if (env->position->x_offset > 4 - .5 / env->position->zoom)
		env->position->x_offset = 4 - .5 / env->position->zoom;
	if (env->position->y_offset < 0)
		env->position->y_offset = 0;
	if (env->position->y_offset > 4 - .5 / env->position->zoom)
		env->position->y_offset = 4 - .5 / env->position->zoom;
	env->position->x_min = (-2.) + env->position->x_offset;
	env->position->x_max = 4. / env->position->zoom + env->position->x_min;
	env->position->y_min = (-2.) + env->position->y_offset;
	env->position->y_max = 4. / env->position->zoom + env->position->y_min;
	if (env->position->density < .1)
		env->position->density = .1;
}

int		expose_hook(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	check_position(env);
	draw(env);
	return (0);
}

int		key_hook(int key, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (key == 53)
		exit(1);
	if (key == 69)
		env->position->zoom *= 1.5;
	if (key == 78)
		env->position->zoom /= 1.5;
	if (key == 123)
		env->position->x_offset -= .5 / env->position->zoom;
	if (key == 124)
		env->position->x_offset += .5 / env->position->zoom;
	if (key == 125)
		env->position->y_offset += .5 / env->position->zoom;
	if (key == 126)
		env->position->y_offset -= .5 / env->position->zoom;
	if (key == 67)
		env->position->density *= 1.5;
	if (key == 75)
		env->position->density /= 1.5;
	check_position(env);
	draw(env);
	return (0);
}

int		mouse_hook(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (env->fractal == 2)
	{
		env->position->julia_x_factor = (double)x / (double)env->window->width;
		env->position->julia_y_factor = (double)y / (double)env->window->height;
		if (env->position->julia_x_factor < 0)
			env->position->julia_x_factor = 0;
		if (env->position->julia_y_factor < 0)
			env->position->julia_y_factor = 0;
		if (env->position->julia_x_factor > 1)
			env->position->julia_x_factor = 1;
		if (env->position->julia_y_factor > 1)
			env->position->julia_y_factor = 1;
		check_position(env);
		draw(env);
	}
	return (0);
}
