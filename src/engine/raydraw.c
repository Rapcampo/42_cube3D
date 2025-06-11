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

void	verline(int x, int ystart, int yend, int color);

void	raydraw(t_dda *dda)
{
	int		line_height;
	int		drawstart;
	int		drawend;

	line_height = (int)(g()->frame.height / dda->wdist);
//	printf("%d\n", line_height);
	drawstart = fmax(-(line_height >> 1) + (g()->frame.height >> 1), 0);
	drawend = (line_height >> 1) + (g()->frame.height >> 1);
	if (drawend >= g()->frame.height)
		drawend = g()->frame.height -1;
	if (drawstart == 0)
		drawstart = (-(line_height >> 1) + (g()->frame.height >> 1));
	if (dda->side == 1)
		verline(dda->x, drawstart, drawend, HEX_COB >> 1);
	else
		verline(dda->x, drawstart, drawend, HEX_PRP);
}

void	verline(int x, int ystart, int yend, int color)
{
	t_data *frame;

	frame = &g()->frame;
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
		pixel_put(frame, x, ystart++, color);
}
