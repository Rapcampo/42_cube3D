/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:19:16 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/18 22:28:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline void	check_chr(char c, int i, int j)
{
	if (c == WALL || c == EMPTY || c == CORR)
		return ;
	else if (c == EAST || c == WEST || c == NORTH || c == SOUTH)
	{
		g()->player.pos.x = i;
		g()->player.pos.y = j;
	}
	else
		exit_log("Error: Invalid character in map.\n");
}

void	find_player(void)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = g()->map.map_data;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			check_chr(map[i][j], i, j);
			j++;
		}
		i++;
	}
}
