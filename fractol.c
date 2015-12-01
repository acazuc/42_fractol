/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 06:28:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 14:02:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "event_listener.h"
#include "minilibx/mlx.h"
#include "env_init.h"
#include "window.h"

int		main(void)
{
	t_env		*env;

	if (!(env = malloc(sizeof(*env))))
		return (-1);
	if (!env_init(env))
		return (-1);
	mlx_key_hook(env->window->mlx_window, &key_hook, env);
	mlx_expose_hook(env->window->mlx_window, &expose_hook, env);
	mlx_hook(env->window->mlx_window, 6, (1 << 6), &mouse_hook, env);
	mlx_loop(env->window->mlx);
	return (0);
}
