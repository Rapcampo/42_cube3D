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

int	render_skybox(t_data *sky)
{
	int		j;
	int		i;

	j = -1;
	i = -1;
	while (++j < HEIGHT >> 1)
	{
		pixel_put(sky, 0, 0 + j, 0x0087ceeb);
		while (++i < WIDTH)
			pixel_put(sky, 0 + i, j, 0x0087ceeb);
		i = -1;
	}
	j = (HEIGHT >> 1) - 1;
	while (++j < HEIGHT)
	{
		pixel_put(sky, 0, 0 + j, FLOOR);
		while (++i < WIDTH)
			pixel_put(sky, 0 + i, j, FLOOR);
		i = -1;
	}
	return (0);
}
