/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 08:49:48 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 09:03:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

# include "complex.h"
# include "dot.h"
# include "env.h"

int			burningship(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot);
void		draw(t_env *env);
void		draw_reset(t_env *env);
void		env_init(t_env *env, char *type);
void		error_quit(char *error_message);
int			expose_hook(void *param);
int			key_hook(int key, void *param);
int			mouse_hook(int x, int y, void *param);
int			julia(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot);
int			mandelbrot(t_env *env, t_complex *c1, t_complex *c2, t_dot *dot);
void		pixel_put(t_env *env, int x, int y, unsigned int color);

#endif
