/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_rec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:13:36 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/20 22:50:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline void	check_line(char *line, int i, int *players)
{
	int	j;
	int	line_size;

	j = 0;
	line_size = g()->map.width;
	while (j < line_size)
	{
		if (j == 0 && !(line[j] == WALL || line[j] == EMPTY))
			exit_log("Error\nInvalid map (open)\n");
		if (j == line_size - 1 && !(line[j] == WALL || line[j] == EMPTY))
			exit_log("Error\nInvalid map (open)\n");
		if (!check_chr(line[j], i, j, players))
			exit_log("Error\nInvalid character in map\n");
		if (line[j] == 0)
		{
			if (j > 0 && line[j - 1] != WALL)
				exit_log("Error\nInvalid map (open)\n");
			while (line[j] == EMPTY)
				j++;
			if (line[j] && line[j] != WALL)
				exit_log("Error\nInvalid map (open)\n");
		}
		if (j < line_size)
			j++;
	}
}

static inline void	hor_ver(t_map map, int *players)
{
	int	i;

	i = 0;
	while (i < g()->map.height)
	{
		check_line(map.map_data[i], i, players);
		i++;
	}
}

static inline void	check_col(char **map, int j, int *players)
{
	int	i;
	int	map_height;

	i = 0;
	map_height = g()->map.height;
	while (i < map_height)
	{
		if (i == 0 && !(map[i][j] == WALL || map[i][j] == EMPTY))
			exit_log("Error\nInvalid map (open)\n");
		if (i == map_height - 1 && !(map[i][j] == WALL || map[i][j] == EMPTY))
			exit_log("Error\nInvalid map (open)\n");
		if (!check_chr(map[i][j], i, j, players))
			exit_log("Error\nInvalid character in map\n");
		if (map[i][j] == 0)
		{
			if (i > 0 && map[i - 1][j] != WALL)
				exit_log("Error\nInvalid map (open)\n");
			while (map[i][j] == EMPTY)
				i++;
			if (map[i][j] && map[i][j] != WALL)
				exit_log("Error\nInvalid map (open)\n");
		}
		if (i < map_height)
			i++;
	}
}

static inline void	vert_ver(t_map map, int *players)
{
	int	j;

	j = 0;
	while (j < g()->map.width)
		check_col(map.map_data, j++, players);
}

void	map_checker(void)
{
	t_map	map;
	int		players;

	players = 0;
	map = g()->map;
	hor_ver(map, &players);
	vert_ver(map, &players);
	// There are "2 players" because we find
	// the position vertically and horizontally
	if (players != 2)
		exit_log("Error\nWrong number of players\n");
}
