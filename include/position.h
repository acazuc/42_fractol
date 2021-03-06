/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:40:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 13:29:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

typedef struct		s_position
{
	double			julia_x_factor;
	double			julia_y_factor;
	double			x_offset;
	double			y_offset;
	double			density;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			zoom;
	double			x;
	double			y;
}					t_position;

#endif
