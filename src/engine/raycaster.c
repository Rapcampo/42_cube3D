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
static void	ray_touch(t_dda *dda);
static t_dda	cast_ray(int x, t_player *p);
static t_dda	*ray_angle(t_dda *dda);
static void		raydraw(t_dda *dda);

static t_dda	*ray_angle(t_dda *dda)
{
	if (dda->ray.x < 0)
	{
		dda->step.x = -1;
		dda->s_inc.x = (g()->player.pos.x - dda->map.x) * dda->delta.x;
	}
	else
	{
		dda->step.x = 1;
		dda->s_inc.x = (dda->map.x + 1 - g()->player.pos.x) * dda->delta.x;
	}
	if (dda->ray.y < 0)
	{
		dda->step.y = -1;
		dda->s_inc.y = (g()->player.pos.y - dda->map.y) * dda->delta.y;
	}
	else
	{
		dda->step.y = 1;
		dda->s_inc.y = (dda->map.y + 1 - g()->player.pos.y) * dda->delta.y;
	}
	return (dda);
}

static t_dda	cast_ray(int x, t_player *p)
{
	const float	camx = (x << 1) / (float)g()->frame.width - 1;	
	t_dda	dda;

	ft_bzero(&dda, sizeof(t_dda));
	dda.x = x;
	dda.ray.x = p->dir.x + p->plane.x * camx;
	dda.ray.y = p->dir.y + p->plane.y * camx;
	dda.map.x = (int)round(p->pos.x);
	dda.map.y = (int)round(p->pos.y);
	dda.delta.x = fabs(1 / dda.ray.x);
	dda.delta.y = fabs(1 / dda.ray.y);
	return (*ray_angle(&dda));
}

static void	ray_touch(t_dda *dda)
{
	dda->touch = 0;
	while (dda->touch == 0)
	{
		if (dda->s_inc.x < dda->s_inc.y)
		{
			dda->s_inc.x += dda->delta.x;
			dda->map.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->s_inc.y += dda->delta.y;
			dda->map.y += dda->step.y;
			dda->side = 1;
		}
//		pixel_put(&g()->frame, dda->map.x * (float)round(g()->frame.width / g()->map.width),
//				dda->map.y * (float)round(g()->frame.height / g()->map.height) , HEX_GRN);
		if (map_coord(dda->map.x, dda->map.y) > 0)
			dda->touch = 1;
		else if (map_coord(dda->map.x, dda->map.y) != 0)
			break ;
	}
	if (dda->side == 0)
	//	dda->wdist = (dda->map.x - g()->player.pos.x + ((1 - dda->step.x) >> 1)) / dda->ray.x;
		dda->wdist = 2;
	else
		dda->wdist = 1;
	//	dda->wdist = (dda->map.y - g()->player.pos.y + ((1 - dda->step.y) >> 1)) / dda->ray.y;
}

static void	raydraw(t_dda *dda)
{
	int		line_height;
	int		drawstart;
	int		drawend;

	line_height = (int)round(g()->frame.height / dda->wdist);
	printf("%d\n", line_height);
	drawstart = fmax(-(line_height >> 1) + (g()->frame.height >> 1), 0);
	drawend = (line_height >> 1) + (g()->frame.height >> 1);
	if (drawend >= g()->frame.height)
		drawend = g()->frame.height -1;
	if (drawstart == 0)
		drawstart = (-(line_height >> 1) + (g()->frame.height >> 1));
	while (drawstart < drawend)
	{
		if (dda->side == 1)
			pixel_put(&g()->vframe, dda->x, drawstart, HEX_WHT >> 1);
		else
			pixel_put(&g()->vframe, dda->x, drawstart, HEX_WHT);
		drawstart++;
	}

}

/*void	verline(int x, int ystart, int yend, int color)
{
	t_data *frame;

	frame = &g()->vframe;
	if (ystart > yend)
	{
		ystart ^= yend;
		yend ^= ystart;
		ystart ^= yend;
	}
	if (ystart < 0)
		ystart = 0;
	else if (ystart >= frame->height)
		yend = frame->height;
	while (ystart < yend)
		pixel_put(frame, x, ystart++, HEX_PRP);
}*/

void	raycaster(void)
{
	t_dda	dda;

	ft_bzero(&dda, sizeof(t_dda));
	dda.x = 0;
	while (dda.x < g()->frame.width)
	{
		dda = cast_ray(dda.x, &g()->player);
		ray_touch(&dda);
		raydraw(&dda);
		dda.x++;
	}
}
