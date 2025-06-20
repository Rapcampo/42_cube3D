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

void	render_mov(t_player *p)
{
	const float		xmov = g()->key[D] - g()->key[A];
	const float		ymov = g()->key[W] - g()->key[S];
	const double	dt = g()->time.delta;
	const double	xform = (xmov * MOV_SPEED * dt);
	const double	yform = (ymov * MOV_SPEED * dt);

	if (xmov != 0
		&& !map_coord(floor(p->pos.x + xform * -p->dir.y), floor(p->pos.y)))
		p->pos.x += xform * -p->dir.y;
	if (xmov != 0
		&& !map_coord(floor(p->pos.x), floor(p->pos.y + xform * p->dir.x)))
		p->pos.y += xform * p->dir.x;
	if (ymov != 0
		&& !map_coord(floor(p->pos.x + yform * p->dir.x), floor(p->pos.y)))
		p->pos.x += yform * p->dir.x;
	if (ymov != 0
		&& !map_coord(floor(p->pos.x), floor(p->pos.y + yform * p->dir.y)))
		p->pos.y += yform * p->dir.y;
}

/*	if (xmov != 0)
		p->pos.x += xform * -p->dir.y;
	if (xmov != 0)
		p->pos.y += xform * p->dir.x;
	if (ymov != 0)
		p->pos.x += yform * p->dir.x;
	if (ymov != 0)
		p->pos.y += yform * p->dir.y;
		*/

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

int	event_keypress(int keycode, t_game *g)
{
	if (g == NULL)
		return (-1);
	if (keycode < 0xFF)
		g->key[keycode & 0xFF] = 1;
	if (keycode == LEFT)
		g->key[1] = 1;
	if (keycode == RIGHT)
		g->key[2] = 1;
	return (0);
}

int	event_keylift(int keycode, t_game *g)
{
	if (g == NULL)
		return (-1);
	if (keycode == ESC)
		clean_exit();
	if (keycode < 0xFF)
		g->key[keycode & 0xFF] = 0;
	if (keycode == LEFT)
		g->key[1] = 0;
	if (keycode == RIGHT)
		g->key[2] = 0;
	return (0);
}
