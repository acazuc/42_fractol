/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:59:38 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 13:37:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_JULIA_H
# define FT_JULIA_H

# include "complex.h"
# include "dot.h"
# include "env.h"

int		julia(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot);

#endif
