/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 06:28:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/08 09:07:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "event_listener.h"
#include "minilibx/mlx.h"
#include "error_quit.h"
#include "env_init.h"
#include "window.h"

int		main(int ac, char **av)
{
	t_env		*env;

	if (ac != 2)
		error_quit("Usage: ./fractol [mandebrot, julia, burningship]");
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env_init(env, av[1]);
	mlx_key_hook(env->window->mlx_window, &key_hook, env);
	mlx_expose_hook(env->window->mlx_window, &expose_hook, env);
	mlx_hook(env->window->mlx_window, 6, (1 << 6), &mouse_hook, env);
	mlx_loop(env->window->mlx);
	return (0);
}
