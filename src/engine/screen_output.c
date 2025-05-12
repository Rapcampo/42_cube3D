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



static void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->ll) + (x * (data->bpp / 8)));
	*(unsigned int *)dst = color;
}

int	init_skybox(t_data *sky, t_data *floor)
{
	sky->img = mlx_new_image(g()->mlx.ptr, 100, 100);
	floor->img = mlx_new_image(g()->mlx.ptr, 100, 100);
	sky->addr = mlx_get_data_addr(sky->img, &sky->bpp, &sky->ll, &sky->endian);
	floor->addr = mlx_get_data_addr(floor->img, &floor->bpp, &floor->ll, &floor->endian);
	return (0);
}

int	output_game(void)
{
	t_data *sky;
	t_data *floor;
	int		i;

	i = 0;
	sky = &g()->skybox.sky;
	floor = &g()->skybox.floor;
	pixel_put(sky, 10, 10, 0x00FF0000);
	pixel_put(floor, 20, 20, 0x0000FF00);
	mlx_put_image_to_window(g()->mlx.ptr, g()->mlx.win, sky->img, 0 + i, 0);
	mlx_put_image_to_window(g()->mlx.ptr, g()->mlx.win, floor->img, 200, 200);
	return (0);
}
