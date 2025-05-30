/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:48:56 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/16 11:49:57 by rapcampo         ###   ########.fr       */
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
static void	put_block(int start_x, int start_y, t_data *frame, int m)
{
	const int cell_h = HEIGHT / g()->map.height;
	const int cell_w = WIDTH / g()->map.width;
	int	h;
	int	w;

	h = -1;
	while (++h < cell_h)
	{
		w = -1;
		while (++w < cell_w)
		{
			if (h == 0 || h == cell_h || w == 0 || w == cell_w)
				pixel_put(frame, start_x + w, start_y + h, 0x00FFFFFF);
			else if (g()->map.map_data[m] == 1)
				pixel_put(frame, start_x + w, start_y + h, 0x004b0082);
			else
				pixel_put(frame, start_x + w, start_y + h, 0x00);
		}
	}

}

static void	put_player(int start_x, int start_y, t_data *frame)
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
				pixel_put(frame, start_x + w, start_y + h, 0x00FF0000);
		}
	}
}

int	render_frame(t_data *frame)
{
	const int cell_h = HEIGHT / g()->map.height;
	const int cell_w = WIDTH / g()->map.width;
	const int limit = g()->map.width * g()->map.height;
	t_map	*map;
	int		m;
	int		start_x;
	int		start_y;

	map = &g()->map;
	m = -1;	
	while (++m < limit){
		start_x = (m % map->width) * (cell_w);
		start_y = (m / map->width) * (cell_h);
		put_block(start_x, start_y, frame, m);
	}
	put_player(g()->player.x * cell_w, g()->player.y * cell_h, frame);
	return (0);
}


