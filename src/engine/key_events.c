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

static int	is_invalid_move(int xmov, int ymov)
{
	const float x = xmov * MOV_SPEED * g()->player.pos.x * g()->player.dir.x * g()->time.delta;
	const float y = ymov * MOV_SPEED * g()->player.pos.y * g()->player.dir.y * g()->time.delta;
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
	const	float	xmov = g()->key[D] - g()->key[A];
	const	float	ymov = g()->key[S] - g()->key[W];
	t_player *p;

	p = &g()->player;
	if (xmov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.x += xmov * MOV_SPEED * g()->time.delta;
	if (ymov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.y += ymov * MOV_SPEED * g()->time.delta;
}

void	render_rot()
{
	const float	rot_dir = g()->key[2] - g()->key[1];
	const float	velo = rot_dir * ROT_SPEED * g()->time.delta;
	const float	org_dx = g()->player.dir.x;
	const float	org_dy = g()->player.dir.y;
	const float	org_px = g()->player.plane.x;
	const float	org_py = g()->player.plane.y;
	t_player	*player;

	player = &g()->player;
	player->dir.x = org_dx * cos(velo) - org_dy * sin(velo);
	player->dir.y = org_dx * sin(velo) + org_dy * cos(velo);
	player->plane.x = org_px * cos(velo) - org_py * sin(velo);
	player->plane.y = org_px * sin(velo) + org_py * cos(velo);
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
