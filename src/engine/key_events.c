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

static int	is_invalid_move(int xmov, int ymov)
{
	const int x = (int)round(xmov * MOV_SPEED * g()->player.dir.x * g()->time.delta);
	const int y = (int)round(ymov * MOV_SPEED * g()->player.dir.y * g()->time.delta);
	t_player	*p;

	p = &g()->player;
	if (x)
		if (map_coord((int)p->pos.y, (int)p->pos.x + x) == 1)
			return (1);
	if (y)
		if (map_coord((int)p->pos.y + y, (int)p->pos.x) == 1)
			return (1);
	return (0);
}

void	render_mov()
{
	const	int xmov = g()->key[D] - g()->key[A];
	const	int ymov = g()->key[S] - g()->key[W];
	t_player *p;

	p = &g()->player;
	if (xmov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.x += xmov * MOV_SPEED * g()->time.delta;
	if (ymov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.y += ymov * MOV_SPEED * g()->time.delta;
}

void	render_rot()
{
	const float	rot_dir = g()->key[1] - g()->key[2];
	const float	velo = rot_dir * ROT_SPEED * g()->time.delta;
	const float	org_dx = g()->player.dir.x;
	const float	org_px = g()->player.plane.x;
	t_player	*player;

	player = &g()->player;
	player->dir.x = org_dx * cos(velo) - player->dir.y * sin(velo);
	player->dir.y = org_dx * sin(velo) + player->dir.y * cos(velo);
	player->plane.x = org_px * cos(velo) - player->plane.y * sin(velo);
	player->plane.y = org_px * sin(velo) + player->plane.y * cos(velo);
}

int	event_keypress(int keycode)
{
	if (keycode < 0xFF)
		g()->key[keycode & 0xFF] = 1;
	if (keycode == LEFT)
		g()->key[1] = 1;
	if (keycode == RIGHT)
		g()->key[2] = 1;
	return (0);
}

int	event_keylift(int keycode)
{
	if (keycode == ESC)
		clean_exit();
	if (keycode < 0xFF)
		g()->key[keycode & 0xFF] = 0;
	if (keycode == LEFT)
		g()->key[1] = 0;
	if (keycode == RIGHT)
		g()->key[2] = 0;
	return (0);
}
