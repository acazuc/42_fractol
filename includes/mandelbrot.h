/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:59:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 08:31:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MANDELBROT_H
# define FT_MANDELBROT_H

# include "complex.h"
# include "dot.h"
# include "env.h"

int		mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot);

#endif
