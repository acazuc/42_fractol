/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:14:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:59:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_pixel(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot)
{
	int			f_color;

	if (env->fractal == 1
			|| env->fractal == 2
			|| env->fractal == 3)
	{
		f_color = 0;
		if (env->fractal == 1)
			f_color = mandelbrot(env, c1, c2, dot);
		else if (env->fractal == 2)
			f_color = julia(env, c1, c2, dot);
		else if (env->fractal == 3)
			f_color = burningship(env, c1, c2, dot);
		pixel_put(env, (dot->x - env->position->x_min)
				/ (env->position->x_max - env->position->x_min)
				* env->window->width
				, (dot->y - env->position->y_min)
				/ (env->position->y_max - env->position->y_min)
				* env->window->height
				, f_color);
	}
}

static void		render(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot)
{
	env->position->y = env->position->y_min;
	while (env->position->y <= env->position->y_max)
	{
		env->position->x = env->position->x_min;
		while (env->position->x <= env->position->x_max)
		{
			dot->x = env->position->x;
			dot->y = env->position->y;
			put_pixel(env, c1, c2, dot);
			env->position->x += (env->position->x_max - env->position->x_min)
				/ env->window->width / 1.1;
		}
		env->position->y += (env->position->y_max - env->position->y_min)
			/ env->window->height / 1.1;
	}
}

void			draw(t_env *env)
{
	t_complex	*c1;
	t_complex	*c2;
	t_dot		*dot;

	draw_reset(env);
	if (!(dot = malloc(sizeof(*dot))))
		return ;
	if (!(c1 = malloc(sizeof(*c1))))
	{
		free(dot);
		return ;
	}
	if (!(c2 = malloc(sizeof(*c2))))
	{
		free(dot);
		free(c1);
		return ;
	}
	render(env, c1, c2, dot);
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
	free(dot);
	free(c1);
	free(c2);
}
