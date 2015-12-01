/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:59:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 08:02:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MANDELBROT_H
# define FT_MANDELBROT_H

# include "complex.h"
# include "dot.h"

int		mandelbrot(t_complex *c1, t_complex *c2, t_dot *dot);

#endif
