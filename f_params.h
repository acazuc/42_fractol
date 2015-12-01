/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_params.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:31:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 12:43:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_F_PARAMS_H
# define FT_F_PARAMS_H

# include <stdlib.h>

typedef struct		s_f_param
{
	char			fractal;
	double			zoom;
	double			offset_x;
	double			offset_y;
}					t_f_params;

#endif
