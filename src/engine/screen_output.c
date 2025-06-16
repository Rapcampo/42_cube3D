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

int	init_frame(t_data *frame, t_mlx *mlx)
{
	frame->height = HEIGHT;
	frame->width = WIDTH;
	frame->img = mlx_new_image(mlx->ptr, frame->width, frame->height);
	frame->addr = mlx_get_data_addr(frame->img,
			&frame->bpp, &frame->ll, &frame->endian);
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
	return (0);
}

void	put_los(t_data *minimap, t_dda *dda, t_map *map)
{
	const float	scale_x = minimap->width / map->width;
	const float	scale_y = minimap->height / map->height;

	pixel_put(minimap, dda->map.x * scale_x, dda->map.y * scale_y, HEX_GRN);
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
