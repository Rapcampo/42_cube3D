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

int	get_alpha(int argb)
{
	return (argb >> 24 & 0xff);
}

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
