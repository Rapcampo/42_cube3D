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
