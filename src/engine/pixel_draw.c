/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:48:56 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/31 20:49:57 by rapcampo         ###   ########.fr       */
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

static void	put_block(int start_x, int start_y, t_data *frame, int m)
{
	const int cell_h = (int)ceil(frame->height / g()->map.height);
	const int cell_w = (int)ceil(frame->width/ g()->map.width);
	int	h;
	int	w;

	h = -1;
	while (++h <= cell_h)
	{
		w = -1;
		while (++w <= cell_w)
		{
			if (m == 1)
			{
				if (h == 0 || h == cell_h || w == 0 || w == cell_w)
					pixel_put(frame, start_x + w, start_y + h, (HEX_TRN | HEX_WHT));
				else
					pixel_put(frame, start_x + w, start_y + h, (HEX_TRN | HEX_PRP));
			}
			else
				pixel_put(frame, start_x + w, start_y + h, (HEX_TRN | HEX_BLK));
		}
	}

}

void	put_player(int start_x, int start_y, t_data *frame, int color)
{
	const int	cell_h = (int)ceil(frame->height / g()->map.height);
	const int	cell_w = (int)ceil(frame->height / g()->map.width);
	const int	radius = cell_w >> 3;
	int			h;
	int			w;
	int			dw;
	int			dh;

	h = -1;
	while (++h < cell_h)
	{
		w = -1;
		while (++w < cell_w)
		{
			dw = w - (cell_w >> 1);
			dh = h - (cell_h >> 1);
			if (((dw * dw) + (dh * dh)) <= (radius * radius))
				pixel_put(frame, start_x + w, start_y + h, color);
		}
	}
}

static void	player_pos_opt(int cell_w, int cell_h, t_player *p, t_data *frame)
{
	static t_fpoint	player;

	put_player(player.x * cell_w, player.y * cell_h, frame,	(HEX_TRN | HEX_BLK));
	player.x = p->pos.x;
	player.y = p->pos.y;
	put_player(p->pos.x * cell_w, p->pos.y * cell_h, frame,(HEX_TRN | HEX_RED));
}

int	render_frame(t_data *frame)
{
	const int cell_h = (int)ceil(frame->height / g()->map.height);
	const int cell_w = (int)ceil(frame->width / g()->map.width);
	t_map			*map;
	t_point			screen;

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
				frame,(HEX_TRN | HEX_RED));
	player_pos_opt(cell_w,cell_h, &g()->player, frame);
	return (0);
}

int	render_game(t_data *frame)
{
	const int	halfscreen = frame->height >> 1;
	int		j;
	int		i;

	j = -1;
	i = -1;
	while (++j < frame->height)
	{
		while (++i < frame->width)
			if (j < halfscreen)
				pixel_put(frame, 0 + i, 0 + j, HEX_COB);
			else
				pixel_put(frame, 0 + i,0 + j, HEX_GRN);
		i = -1;
	}
	return (0);
}
