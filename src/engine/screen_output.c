/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:00:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/12 17:28:25 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_fpoint	scalling_factor(t_game *g, t_fpoint *scale)
{
	t_fpoint	aspect;

	aspect.x = (float)g->minimap.width / (float)g->minimap.height;
	aspect.y = (float)g->map.width / (float)g->map.height;
	if (aspect.x > aspect.y)
	{
		scale->x = (float)g->minimap.height / (float)g->map.height;
		scale->y = scale->x;
	}
	else
	{
		scale->y = (float)g->minimap.width / (float)g->map.width;
		scale->x = scale->y;
	}
	return (*scale);
}

int	init_frame(t_data *frame, t_mlx *mlx)
{
	frame->height = HEIGHT;
	frame->width = WIDTH;
	frame->img = mlx_new_image(mlx->ptr, frame->width, frame->height);
	if (frame->img == NULL)
		exit_log(RED ERR_IMG RST);
	frame->addr = mlx_get_data_addr(frame->img,
			&frame->bpp, &frame->ll, &frame->endian);
	if (frame->addr == NULL)
		exit_log(RED ERR_ADDR RST);
	return (0);
}

int	init_minimap(t_data *minimap, t_mlx *mlx, t_data *frame)
{
	(void)mlx;
	minimap->height = HEIGHT >> 2;
	minimap->width = WIDTH >> 2;
	minimap->img = frame->img;
	minimap->addr = frame->addr;
	minimap->bpp = frame->bpp;
	minimap->endian = frame->endian;
	minimap->ll = frame->ll;
	g()->cell = scalling_factor(g(), &g()->cell);
	return (0);
}

void	put_los(t_data *minimap, t_dda *dda, t_map *map, int print)
{
	const float	scale_x = g()->cell.x;
	const float	scale_y = g()->cell.y;
	static int	x[15000];
	static int	y[15000];
	static int	i;

	(void)map;
	if (print == 0 && i < 15000)
	{
		x[i] = dda->map.x;
		y[i] = dda->map.y;
		i++;
	}
	else if (print == 1)
	{
		i = 0;
		while (i < 15000)
		{
			pixel_put(minimap, x[i] * scale_x, y[i] * scale_y, 0x0000FF00);
			x[i] = 0;
			y[i] = 0;
			i++;
		}
		i = 0;
	}
}

int	render_game(t_data *frame)
{
	const int	halfscreen = frame->height >> 1;
	t_point		coor;
	t_map		*m;

	coor.y = -1;
	coor.x = -1;
	m = &g()->map;
	while (++coor.y < frame->height)
	{
		while (++coor.x < frame->width)
		{
			if (coor.y < halfscreen)
				pixel_put(frame, 0 + coor.x, 0 + coor.y, m->c_color);
			else
				pixel_put(frame, 0 + coor.x, 0 + coor.y, m->f_color);
		}
		coor.x = -1;
	}
	return (0);
}
