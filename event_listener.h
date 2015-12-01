/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 07:30:04 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/01 07:33:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_LISTENER_H
# define FT_EVENT_LISTENER_H

int		expose_hook(void *param);
int		key_hook(int key, void *param);
int		wheel_hook(int wheel, void *paran);
int		mouse_hook(int button, void *param);

#endif
