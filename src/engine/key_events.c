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

/*static int	sky_part(t_data *sky, t_data *floor)
{
	t_mlx	*mlx;
	int		j;
	int		i;

	mlx = &g()->mlx;
	j = -1;
	i = -1;
	//mlx_clear_window(mlx->ptr, mlx->win);
	while (++j < HEIGHT >> 1)
	{
		pixel_put(sky, 0, 0 + j, 0x00FF0000);
		pixel_put(floor, 0, 0 + j, 0x0000FF);
		while (++i < WIDTH)
		{
			pixel_put(sky, 0 + i, j, 0x00FF0000);
			pixel_put(floor, 0 + i, j, 0x000000FF);
		}
		i = -1;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, sky->img, 0, 0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, floor->img, 0, HEIGHT >> 1);
	return (0);
}*/
//placeholder eventkeys function just to be able to quit window.
int	event_keypress(int keycode)
{
	//OBS.: this exit should probably be in keylift
	if (keycode <= 65000)
		return 0;
//		sky_part(&g()->skybox.sky, &g()->skybox.floor);
//		execute_movement();
//	if (keycode == LEFT || keycode == RIGHT)
//		rot_axis();
	return (0);
}

int	event_keylift(int keycode)
{
	if (keycode == ESC)
		clean_exit();
//	else if (keycode <= 65000)
//		stop_movement();
//	else if (keycode == LEFT || keycode == RIGHT)
//		stop_rotation();
	return (0);
}
