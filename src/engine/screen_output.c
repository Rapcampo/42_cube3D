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



void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*offset;

	offset = data->addr + ((y * data->ll) + (x * (data->bpp >> 3)));
	*(unsigned int *)offset = color;
}

int	init_skybox(t_data *sky, t_data *floor)
{
	sky->img = mlx_new_image(g()->mlx.ptr, WIDTH, HEIGHT >> 1);
	floor->img = mlx_new_image(g()->mlx.ptr, WIDTH, HEIGHT >> 1);
	sky->addr = mlx_get_data_addr(sky->img, &sky->bpp, &sky->ll, &sky->endian);
	floor->addr = mlx_get_data_addr(floor->img, &floor->bpp
		, &floor->ll, &floor->endian);
	return (0);
}

static int	render_skybox(t_data *sky, t_data *floor)
{
	t_mlx	*mlx;
	int		j;
	int		i;

	mlx = &g()->mlx;
	j = -1;
	i = -1;
	while (++j < HEIGHT >> 1)
	{
		pixel_put(sky, 0, 0 + j, 0x0087ceeb);
		pixel_put(floor, 0, 0 + j, 0x00138510);
		while (++i < WIDTH)
		{
			pixel_put(sky, 0 + i, j, 0x0087ceeb);
			pixel_put(floor, 0 + i, j, 0x00138510);
		}
		i = -1;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, sky->img, 0, 0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, floor->img, 0, HEIGHT >> 1);
	return (0);
}

int	output_game(void)
{
	render_skybox(&g()->skybox.sky, &g()->skybox.floor);
	return (0);
}
