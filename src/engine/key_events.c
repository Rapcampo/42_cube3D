/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:56:37 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/08 12:00:46 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//placeholder eventkeys function just to be able to quit window.
int	event_keypress(int keycode)
{
	(void)keycode;
	//OBS.: this exit should probably be in keylift
//	if (keycode <= 65000)
//		execute_movement();
//	if (keycode == LEFT || keycode == RIGHT)
//		rot_axis();
	return (0);
}

int	event_keylift(int keycode)
{
	if (keycode == ESC || keycode == Q)
		clean_exit();
//	else if (keycode <= 65000)
//		stop_movement();
//	else if (keycode == LEFT || keycode == RIGHT)
//		stop_rotation();
	return (0);
}
