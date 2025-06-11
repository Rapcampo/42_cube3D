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
//	t_player	*p;
	(void)ymov, (void)xmov;

//	p = &g()->player;
/*	if (xmov != 0)
	{
		return (map_coord((int)(p->pos.x + xmov * MOV_SPEED * -p->dir.y * g()->time.delta),		(int)(p->pos.y += xmov * MOV_SPEED * p->dir.x * g()->time.delta)));
	}
	if (ymov != 0)
		return (map_coord((int)(p->pos.x + ymov * MOV_SPEED * -p->dir.x * g()->time.delta),(int)(p->pos.y += ymov * MOV_SPEED * p->dir.y * g()->time.delta)));
		*/
	return (0);
}

void	render_mov()
{
	const	float	xmov = g()->key[D] - g()->key[A];
	const	float	ymov = g()->key[W] - g()->key[S];
	const	float	dt = g()->time.delta;
	t_player *p;
	
	p = &g()->player;
	if (xmov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.x += xmov * MOV_SPEED * -p->dir.y * dt;
	if (xmov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.y += xmov * MOV_SPEED * p->dir.x * dt;
	if (ymov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.x += ymov * MOV_SPEED * p->dir.x * dt;
	if (ymov != 0 && !is_invalid_move(xmov, ymov))
		p->pos.y += ymov * MOV_SPEED * p->dir.y * dt;
}

void	render_rot()
{
	const float	rot_dir = g()->key[2] - g()->key[1];
	const float	velo = rot_dir * ROT_SPEED * g()->time.delta;
	const float	org_dx = g()->player.dir.x;
	const float	org_px = g()->player.plane.x;
	t_player	*player;

	player = &g()->player;
	player->dir.x = player->dir.x * cos(velo) - player->dir.y * sin(velo);
	player->dir.y = org_dx * sin(velo) + player->dir.y * cos(velo);
	player->plane.x = player->plane.x * cos(velo) - player->plane.y * sin(velo);
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
