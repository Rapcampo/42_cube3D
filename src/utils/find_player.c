/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:19:16 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/20 21:56:45 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: Use function that Raphael made (after merge)
static inline void	save_dir(char c)
{
	if (c == EAST)
		g()->player.dir.y = 1.0;
	else if (c == WEST)
		g()->player.dir.y = -1.0;
	else if (c == NORTH)
		g()->player.dir.x = 1.0;
	else if (c == SOUTH)
		g()->player.dir.x = -1.0;

}

inline int	check_chr(char c, int i, int j, int *players)
{
	if (c == WALL || c == EMPTY || c == CORR)
		return (1);
	else if (c == EAST || c == WEST || c == NORTH || c == SOUTH)
	{
		g()->player.pos.x = j;
		g()->player.pos.y = i;
		save_dir(c);
		(*players)++;
		return (1);
	}
	else
		exit_log("Error: Invalid character in map.\n");
	return (0);
}

// // TODO: Realocate the map to have a constant width (fill empty char with wall)
// void	find_player(void)
// {
// 	int		i;
// 	int		j;
// 	int		count_players;
// 	char	**map;

// 	i = 0;
// 	count_players = 0;
// 	map = g()->map.map_data;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			count_players += check_chr(map[i][j], i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (count_players != 1)
// 		exit_log("Error: Incorrect amount of players in the map\n");
// }
