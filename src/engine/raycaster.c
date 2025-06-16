/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:04:17 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/30 19:15:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//todo: dda propper implementation
static void		ray_touch(t_dda *dda, t_player *p);
static t_dda	cast_ray(int x, t_player *p);
static t_dda	*ray_angle(t_dda *dda, t_fpoint *pos);
static float	calculate_distance(t_dda *dda, t_player *p, int side);

static t_dda	*ray_angle(t_dda *dda, t_fpoint *pos)
{
	if (dda->ray.x < 0)
	{
		dda->step.x = -1;
		dda->sdist.x = (pos->x - dda->map.x) * dda->delta.x;
	}
	else
	{
		dda->step.x = 1;
		dda->sdist.x = (dda->map.x + 1 - pos->x) * dda->delta.x;
	}
	if (dda->ray.y < 0)
	{
		dda->step.y = -1;
		dda->sdist.y = (pos->y - dda->map.y) * dda->delta.y;
	}
	else
	{
		dda->step.y = 1;
		dda->sdist.y = (dda->map.y + 1 - pos->y) * dda->delta.y;
	}
	return (dda);
}

static t_dda	cast_ray(int x, t_player *p)
{
	const float	camx = (x << 1) / (float)g()->frame.width - 1;	
	t_dda		dda;

	ft_bzero(&dda, sizeof(t_dda));
	dda.x = x;
	dda.ray.x = p->dir.x + p->plane.x * camx;
	dda.ray.y = p->dir.y + p->plane.y * camx;
	dda.map.x = (int)(p->pos.x);
	dda.map.y = (int)(p->pos.y);
	dda.delta.x = fabs(1 / dda.ray.x);
	dda.delta.y = fabs(1 / dda.ray.y);
	return (*ray_angle(&dda, &p->pos));
}

static void	ray_touch(t_dda *dda, t_player *p)
{
	dda->touch = 0;
	while (dda->touch == 0)
	{
		if (dda->sdist.x < dda->sdist.y)
		{
			dda->sdist.x += dda->delta.x;
			dda->map.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->sdist.y += dda->delta.y;
			dda->map.y += dda->step.y;
			dda->side = 1;
		}
		put_los(&g()->minimap, dda, &g()->map);
		if (map_coord(dda->map.x, dda->map.y) > 0)
			dda->touch = 1;
		else if (map_coord(dda->map.x, dda->map.y) < 0)
			break ;
	}
	dda->wdist = calculate_distance(dda, p, dda->side);
}

static float	calculate_distance(t_dda *dda, t_player *p, int side)
{
	if (side == 0)
		return ((dda->map.x - p->pos.x
				+ ((1 - dda->step.x) >> 1)) / dda->ray.x);
	else
		return ((dda->map.y - p->pos.y
				+ ((1 - dda->step.y) >> 1)) / dda->ray.y);
}

void	raycaster(void)
{
	t_dda		dda;
	t_player	*p;

	p = &g()->player;
	ft_bzero(&dda, sizeof(t_dda));
	dda.x = -1;
	render_frame(&g()->minimap);
	while (++dda.x < g()->frame.width)
	{
		dda = cast_ray(dda.x, p);
		ray_touch(&dda, p);
		if (dda.side == 0 && dda.ray.x > 0)
			raydraw(&dda, &g()->textures->north);
		else if (dda.side == 0 && dda.ray.x < 0)
			raydraw(&dda, &g()->textures->south);
		else if (dda.side == 1 && dda.ray.y > 0)
			raydraw(&dda, &g()->textures->east);
		else if (dda.side == 1 && dda.ray.y < 0)
			raydraw(&dda, &g()->textures->west);
	}
}
