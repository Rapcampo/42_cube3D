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
	render_frame(frame);
	return (0);
}

void	render_mov()
{
	const	int xmov = g()->key[D] - g()->key[A];
	const	int ymov = g()->key[S] - g()->key[W];
	t_player *p;

	p = &g()->player;
	if (xmov != 0)
		p->pos.x += xmov * MOV_SPEED * g()->time.delta;
	if (ymov != 0)
		p->pos.y += ymov * MOV_SPEED * g()->time.delta;
}

void	render_rot()
{
	const float	rot_dir = g()->key[1] - g()->key[2];
	const float	velo = rot_dir * ROT_SPEED * g()->time.delta;
	const float	org_dx = g()->player.dir.x;
	const float	org_px = g()->player.plane.x;

	g()->player.dir.x = org_dx * cos(velo) - g()->player.dir.y * sin(velo);
	g()->player.dir.y = org_dx * sin(velo) + g()->player.dir.y * cos(velo);
	g()->player.plane.x = org_px * cos(velo) - g()->player.plane.y * sin(velo);
	g()->player.plane.y = org_px * sin(velo) + g()->player.plane.y * cos(velo);
}

/*void	render_mov(){
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
}*/
