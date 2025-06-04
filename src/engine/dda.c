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

float	deg_to_rad(float a)
{
	return (a * M_PI / 180);
}

float	fix_angle(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float distance(t_dda *dda)
{
	return (cos(deg_to_rad(ang)) * (bx-ax)-sin(deg_to_rad(ang)) * (by-ay));
}

int	dda(t_dda *dda)
{
	int	i;
	//base of the algorythmn
	i = -1;
	dda->dx = dda->x0 - dda->x1;
	dda->dy = dda->y0 - dda->y1;
	if (abs(dx) > abs(dy))
		dda->steps = dda->dx;
	else
		dda->steps = dda->dy;
	dda->xinc = dda->dx / (float)dda->steps;
	dda->yinc = dda->dy / (float)dda->steps;
	dda->fx = dda->x0;
	dda->fy = dda->y0;
	while (++i <= dda->steps)
	{
		pixel_put(&g()->frame, round(dda->fx), round(dda->fy), 0x0000FF00);
		dda->fx += dda->xinc;
		dda->fy += dda->yinc;
	}
	return (0);
}
