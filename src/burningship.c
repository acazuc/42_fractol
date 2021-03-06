/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:51:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 08:58:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	abc(double n)
{
	return (n < 0 ? -n : n);
}

static int		get_color(float i, float max_i)
{
	if (max_i == i)
		return (0);
	return ((int)(0xFF0000 * i / max_i) / 0x010000 * 0x010000);
}

int				burningship(t_env *env, t_complex *c1, t_complex *c2
		, t_dot *dot)
{
	int			max_i;
	int			i;

	max_i = 50 * env->position->density;
	i = 0;
	c1->real = 0;
	c1->imaginary = 0;
	while (i < max_i && (c1->real * c1->real + c1->imaginary
				* c1->imaginary) < 4)
	{
		c2->real = abc(c1->real);
		c2->imaginary = abc(c1->imaginary);
		c1->real = c2->real * c2->real - c2->imaginary * c2->imaginary
			+ dot->x;
		c1->imaginary = 2. * c2->real * c2->imaginary + dot->y / 1.777777;
		i++;
	}
	return (get_color(i, max_i));
}
