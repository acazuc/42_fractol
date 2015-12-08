/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_coords.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:30:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 09:03:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_COORDS_H
# define FT_RENDER_COORDS_H

typedef struct		s_render_coords
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			x;
	double			y;
}					t_render_coords;

#endif
