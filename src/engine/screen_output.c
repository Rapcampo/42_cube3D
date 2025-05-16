/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:00:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/12 17:28:25 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//static void	create_frame();

int	init_skybox(t_data *sky)
{
	sky->height = HEIGHT;
//	floor->height = HEIGHT >> 1;
	sky->width = WIDTH;
//	floor->width = WIDTH;
	sky->img = mlx_new_image(g()->mlx.ptr, sky->width, sky->height);
//	floor->img = mlx_new_image(g()->mlx.ptr, floor->width, floor->height);
	sky->addr = mlx_get_data_addr(sky->img, &sky->bpp, &sky->ll, &sky->endian);
//	floor->addr = mlx_get_data_addr(floor->img, &floor->bpp
//		, &floor->ll, &floor->endian);
	return (0);
}

int	gameloop(void)
{
//	create_frame();
	get_time_delta();
	printf("Current FPS: %f\r", g()->time.fps);
	render_skybox(&g()->skybox.sky);
	mlx_put_image_to_window(g()->mlx.ptr, g()->mlx.win, g()->skybox.sky.img, 0, 0);
	//mlx_string_put(&g()->mlx.ptr, &g()->mlx.win, 10, 10, 0x00FFFFFF, ft_itoa((int)g()->time.fps));
	return (0);
}
