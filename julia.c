/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:51:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 09:04:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "complex.h"
#include "env.h"
#include "dot.h"

static int	get_color(double i, double max_i)
{
	if (max_i == i)
		return (0);
	if (i < 50)
		return (0x0000FF * i / 50);
	return (0x0000FF + 0xFFFF00 * i / 100);
}

int			julia(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot)
{
	int			max_i;
	int			i;

	max_i = 100;
	i = 0;
	c1->real = dot->x;
	c1->imaginary = dot->y;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = c1->real;
		c2->imaginary = c1->imaginary;
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary - 0.7
			- env->position->julia_x_factor / 10.0;
		c1->imaginary = 2 * c2->real * c2->imaginary + 0.27
			+ env->position->julia_y_factor / 10.0;
		i++;
	}
	return (get_color(i, max_i));
}
