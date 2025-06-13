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

/*static int	is_invalid_move(int xmov, int ymov, int type, t_player *p)
{
	const float	dt = g()->time.delta;
	const int	mv1 = (int)(p->pos.x + xmov * MOV_SPEED * -p->dir.y * dt);
	const int	mv2 = (int)(p->pos.y + xmov * MOV_SPEED * p->dir.x * dt);
	const int	mv3 = (int)(p->pos.x + ymov * MOV_SPEED * p->dir.x * dt);
	const int	mv4 = (int)(p->pos.y + ymov * MOV_SPEED * p->dir.y * dt);

	if (xmov != 0)
	{
		if (type == 1 && map_coord(mv1, p->pos.y) == 1)
			return (1);
		if (type == 2 && map_coord(p->pos.x, mv2) == 1)
			return (1);
	}
	if (ymov != 0)
	{
		if (type == 3 && map_coord(mv3, p->pos.y) == 1)
			return (1);
		if (type == 4 && map_coord(p->pos.x, mv4) == 1)
			return (1);
	}
	return (0);
}*/

void	render_mov(t_player *p)
{
	const float	xmov = g()->key[D] - g()->key[A];
	const float	ymov = g()->key[W] - g()->key[S];
	const float	dt = g()->time.delta;
	const float mv1 = (xmov * MOV_SPEED * -p->dir.y * dt);
	const float mv2 = (xmov * MOV_SPEED * p->dir.x * dt);
	const float mv3 = (ymov * MOV_SPEED * p->dir.x * dt);
	const float mv4 = (ymov * MOV_SPEED * p->dir.y * dt);
	if (xmov != 0 && !map_coord((int)(p->pos.x + mv1), p->pos.y))
		p->pos.x += mv1;
	if (xmov != 0 && !map_coord(p->pos.x, (int)(p->pos.y + mv2)))
		p->pos.y += mv2;
	if (ymov != 0 && !map_coord((int)p->pos.x + mv3, p->pos.y))
		p->pos.x += mv3;
	if (ymov != 0 && !map_coord(p->pos.x, (int)(p->pos.y + mv4)))
		p->pos.y += mv4;
	/*if (xmov != 0)
		p->pos.x += xmov * MOV_SPEED * -p->dir.y * dt;
	if (xmov != 0)
		p->pos.y += xmov * MOV_SPEED * p->dir.x * dt;
	if (ymov != 0)
		p->pos.x += ymov * MOV_SPEED * p->dir.x * dt;
	if (ymov != 0)
		p->pos.y += ymov * MOV_SPEED * p->dir.y * dt;
		*/
}

void	render_rot(t_player *player)
{
	const float	rot_dir = g()->key[2] - g()->key[1];
	const float	velo = rot_dir * ROT_SPEED * g()->time.delta;
	const float	org_dx = player->dir.x;
	const float	org_px = player->plane.x;
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
