/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:19:16 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 11:02:13 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

inline int	check_chr(char c, int i, int j, int *players)
{
	t_point	pos;

	pos.x = 0;
	pos.y = 0;
	if (c == WALL || c == EMPTY || c == CORR)
		return (1);
	else if (c == EAST || c == WEST || c == NORTH || c == SOUTH)
	{
		pos.x = j;
		pos.y = i;
		set_player(&g()->player, &pos, c);
		g()->map.map_data[i][j] = CORR;
		(*players)++;
		return (1);
	}
	return (0);
}
