/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:48:56 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/21 17:36:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*offset;

	if ((x < 0 || 0 > y) || (data->width <= x || y >= data->height))
		return ;
	offset = data->addr + ((y * data->ll) + (x * (data->bpp >> 3)));
	*(unsigned int *)offset = color;
}

static void	put_block(int start_x, int start_y, t_data *frame, char m)
{
	const int	cell_h = (int)g()->cell.y;
	const int	cell_w = (int)g()->cell.x;
	int			h;
	int			w;

	h = -1;
	while (++h <= cell_h)
	{
		w = -1;
		while (++w <= cell_w)
		{
			if (m == WALL)
			{
				if (h == 0 || h == cell_h || w == 0 || w == cell_w)
					pixel_put(frame, start_x + w, start_y + h, HEX_WHT);
				else
					pixel_put(frame, start_x + w, start_y + h, HEX_PRP);
			}
			else
				pixel_put(frame, start_x + w, start_y + h, HEX_BLK);
		}
	}
}

void	put_player(int start_x, int start_y, t_data *frame, int color)
{
	const int	cell_h = (int)g()->cell.y;
	const int	cell_w = (int)g()->cell.x;
	const int	radius = cell_w >> 2;
	t_point		cell;
	t_point		delta;

	cell.y = -1;
	while (++cell.y < cell_h)
	{
		cell.x = -1;
		while (++cell.x < cell_w)
		{
			delta.x = cell.x - (cell_w >> 1);
			delta.y = cell.y - (cell_h >> 1);
			if (((delta.x * delta.x) + (delta.y * delta.y))
				<= (radius * radius))
				pixel_put(frame, start_x + delta.x, start_y + delta.y, color);
		}
	}
}

int	render_frame(t_data *frame)
{
	const int	cell_h = (int)g()->cell.y;
	const int	cell_w = (int)g()->cell.x;
	t_map		*map;
	t_point		screen;

	map = &g()->map;
	screen.y = -1;
	screen.x = -1;
	while (++screen.y < map->height)
	{
		screen.x = -1;
		while (++screen.x < map->width)
			put_block(screen.x * cell_w, screen.y * cell_h,
				frame, map->map_data[screen.y][screen.x]);
	}
	put_player(g()->player.pos.x * cell_w, g()->player.pos.y * cell_h,
		frame, HEX_RED);
	return (0);
}
