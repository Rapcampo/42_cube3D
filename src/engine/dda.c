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

int	dda(t_dda *dda, int x)
{
	//lots of math
	return (0);
}
