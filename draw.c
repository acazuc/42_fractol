/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:14:37 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 13:38:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "render_coords.h"
#include "burningship.h"
#include "mandelbrot.h"
#include "complex.h"
#include "window.h"
#include "julia.h"
#include "env.h"
#include "dot.h"

static void		put_pixel(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot)
{
	int			f_color;

	if (env->fractal == 1
			|| env->fractal == 2
			|| env->fractal == 3)
	{
		f_color = 0;
		if (env->fractal == 1)
			f_color = mandelbrot(c1, c2, dot);
		else if (env->fractal == 2)
			f_color = julia(env, c1, c2, dot);
		else if (env->fractal == 3)
			f_color = burningship(c1, c2, dot);
		mlx_pixel_put(env->window->mlx, env->window->mlx_window
				, (dot->x - env->position->x_min)
				/ (env->position->x_max - env->position->x_min)
				* env->position->zoom * env->window->width
				, (dot->y - env->position->y_min)
				/ (env->position->y_max - env->position->y_min)
				* env->position->zoom * env->window->height
				, mlx_get_color_value(env->window->mlx, f_color));
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
				/ env->window->width / env->position->zoom;
		}
		env->position->y += (env->position->y_max - env->position->y_min)
			/ env->window->height / env->position->zoom;
	}
	ft_putendl("finished");
}

void			draw(t_env *env)
{
	t_complex	*c1;
	t_complex	*c2;
	t_dot		*dot;

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
	free(dot);
	free(c1);
	free(c2);
}
