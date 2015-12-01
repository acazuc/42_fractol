/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:44:23 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/30 16:13:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WINDOW_H
# define FT_WINDOW_H

typedef struct			s_window
{
	void				*mlx_window;
	void				*image;
	void				*mlx;
	int					width;
	int					height;
}						t_window;

#endif
