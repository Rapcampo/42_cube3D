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

void	render_mov(){
	int		j;
	int		i;
	t_data *frame;

	if (g()->key[0] || g()->key[6] || g()->key[3] || g()->key[2]){
		frame = &g()->skybox.sky;
		j = -1;
		i = -1;
		while (++j < HEIGHT >> 1)
		{
			pixel_put(frame, 0, 0 + j, 0x0087ceeb >> 1);
			while (++i < WIDTH)
				pixel_put(frame, 0 + i, j, 0x0087ceeb >> 1);
			i = -1;
		}
		j = (HEIGHT >> 1) - 1;
		while (++j < HEIGHT)
		{
			pixel_put(frame, 0, 0 + j, FLOOR >> 1);
			while (++i < WIDTH)
				pixel_put(frame, 0 + i, j, FLOOR >> 1);
			i = -1;
		}
	}
}

/*void	render_rot(){

}*/
