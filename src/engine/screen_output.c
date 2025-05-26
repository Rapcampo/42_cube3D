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

int	init_frame(t_data *frame)
{
	frame->height = HEIGHT;
	frame->width = WIDTH;
	frame->img = mlx_new_image(g()->mlx.ptr, frame->width, frame->height);
	frame->addr = mlx_get_data_addr(frame->img,
			&frame->bpp, &frame->ll, &frame->endian);
	return (0);
}

void	render_mov(){
	int		j;
	int		i;
	t_data *frame;

	if (g()->key[A] || g()->key[S] || g()->key[W] || g()->key[D]){
		frame = &g()->frame;
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
