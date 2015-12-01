/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:51:10 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/30 10:48:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_color.h"
#include "complex.h"

int		other_fractal(t_complex *c, t_complex *c2, double x, double y)
{
	int			max_i;
	int			i;

	max_i = 5000;
	i = 0;
	c->real = 0;
	c->imaginary = 0;
	while (i < max_i && (c->real * c->real + c->imaginary * c->imaginary) < 4)
	{
		c2->real = c->real;
		c2->imaginary = c->imaginary;
		c->real = c2->real * c2->real - c2->imaginary * c2->imaginary + x;
		c->imaginary = 2 * c2->real * c2->imaginary - y;
		i++;
	}
	return (get_color(i, max_i));
}
