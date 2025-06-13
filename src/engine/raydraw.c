/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   $dda.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:54 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/16 11:47:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	verline(int x, int y0, int y1, int color);

void	raydraw(t_dda *dda)
{
	const int	h = g()->frame.height;
	int		line_height;
	int		dstart;
	int		dend;

	line_height = (int)(h / dda->wdist);
	dstart = fmax(-(line_height >> 1) + (h >> 1), 0);
	dend = (line_height >> 1) + (h >> 1);
	if (dend >= h)
		dend = h - 1;
	if (dstart == 0)
		dstart = (-(line_height >> 1) + (h >> 1));
	if (dda->side == 1)
		verline(dda->x, dstart, dend, HEX_COB >> 1);
	else
		verline(dda->x, dstart, dend, HEX_PRP);
}

void	verline(int x, int y0, int y1, int color)
{
	t_data *frame;

	frame = &g()->frame;
	if (y0 > y1)
	{
		y0 ^= y1;
		y1 ^= y0;
		y0 ^= y1;
	}
	if (y0 < 0)
		y0 = 0;
	else if (y0 >= frame->height)
		y1 = frame->height;
	while (y0 < y1)
		pixel_put(frame, x, y0++, color);
}
