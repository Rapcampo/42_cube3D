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

static void	put_block(int start_x, int start_y, t_data *frame)
{
	const int cell_h = HEIGHT / g()->map.height;
	const int cell_w = WIDTH / g()->map.width;
	int	h;
	int	w;

	h = -1;
	while (++h <= cell_h)
	{
		w = -1;
		while (++w <= cell_w)
		{
			if (h == 0 || h == cell_h || w == 0 || w == cell_w)
				pixel_put(frame, start_x + w, start_y + h, HEX_WHT);
			else
				pixel_put(frame, start_x + w, start_y + h, HEX_PRP);
		}
	}

}

static void	put_player(int start_x, int start_y, t_data *frame, int color)
{
	const int	cell_h = HEIGHT / g()->map.height;
	const int	cell_w = WIDTH / g()->map.width;
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

		put_player(player.x * cell_w, player.y * cell_h, frame,	HEX_BLK);
		player.x = p->pos.x;
		player.y = p->pos.y;
		put_player(p->pos.x * cell_w, p->pos.y * cell_h, frame,
			HEX_RED);
}

int	render_frame(t_data *frame)
{
	const int cell_h = HEIGHT / g()->map.height;
	const int cell_w = WIDTH / g()->map.width;
	t_map			*map;
	t_point			screen;
	static int r;

	map = &g()->map;
	screen.y = -1;	
	screen.x = -1;
	if (r == 10){
		while (++screen.y < map->height)
		{
			screen.x = -1;
			while (++screen.x < map->width)
				if (map->map_data[screen.y][screen.x] == 1)
				put_block(screen.x * cell_w, screen.y * cell_h, frame);
		}
		put_player(g()->player.pos.x * cell_w, g()->player.pos.y * cell_h,
				frame, HEX_RED);
		r = 0;
	}
	r++;
	player_pos_opt(cell_w,cell_h, &g()->player, frame);
	return (0);
}

/*int	render_frame(t_data *frame)
  {
  int		j;
  int		i;

  j = -1;
  i = -1;
  while (++j < HEIGHT >> 1)
  {
  pixel_put(frame, 0, 0 + j, 0x0087ceeb);
  while (++i < WIDTH)
  pixel_put(frame, 0 + i, j, 0x0087ceeb);
  i = -1;
  }
  j = (HEIGHT >> 1) - 1;
  while (++j < HEIGHT)
  {
  pixel_put(frame, 0, 0 + j, FLOOR);
  while (++i < WIDTH)
  pixel_put(frame, 0 + i, j, FLOOR);
  i = -1;
  }
  return (0);
  }*/
