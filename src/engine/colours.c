/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:07:15 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/16 17:49:12 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_red(int argb)
{
	return (argb >> 16 & 0xff);
}

int	get_green(int argb)
{
	return (argb >> 8 & 0xff);
}

int	get_blue(int argb)
{
	return (argb & 0xff);
}

int	get_argb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

int	darken(int side, int color)
{
	int	r;
	int	g;
	int	b;

	r = get_red(color) >> 1;
	g = get_green(color) >> 1;
	b = get_blue(color) >> 1;
	if (side == 1)
		return (get_argb(0, r, g, b));
	return (color);
}
