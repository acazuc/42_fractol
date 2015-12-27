/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:51:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 08:38:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "complex.h"
#include "dot.h"
#include "env.h"

static int		get_color(double i, double max_i)
{
	if (max_i == i)
		return (0);
	if (i < max_i)
		return (0x0000FF * i / max_i);
	return (0x0000FF + 0xFFFF00 * i / max_i / 1.5);
}

int				mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot)
{
	int			max_i;
	int			i;

	max_i = 40 * env->position->density;
	i = 0;
	c1->real = 0;
	c1->imaginary = 0;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = c1->real;
		c2->imaginary = c1->imaginary;
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary + dot->x;
		c1->imaginary = 2 * c2->real * c2->imaginary + dot->y / 1.777777;
		i++;
	}
	return (get_color(i, max_i));
}
