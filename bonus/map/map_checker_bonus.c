/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:13:36 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:51:22 by tialbert         ###   ########.fr       */
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
			exit_log(RED ERR_MAP_OPEN RST);
		if (j == line_size - 1 && !(line[j] == WALL || line[j] == EMPTY))
			exit_log(RED ERR_MAP_OPEN RST);
		if (!check_chr(line[j], i, j, players))
			exit_log(RED ERR_INV_CHR RST);
		if (line[j] == EMPTY)
		{
			if (j > 0 && line[j - 1] != WALL)
				exit_log(RED ERR_MAP_OPEN RST);
			while (j < line_size - 1 && line[j] == EMPTY)
				j++;
			if (line[j] && line[j] != WALL && line[j] != EMPTY)
				exit_log(RED ERR_MAP_OPEN RST);
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
			exit_log(RED ERR_MAP_OPEN RST);
		if (i == map_height - 1 && !(map[i][j] == WALL || map[i][j] == EMPTY))
			exit_log(RED ERR_MAP_OPEN RST);
		if (!check_chr(map[i][j], i, j, players))
			exit_log(RED ERR_INV_CHR RST);
		if (map[i][j] == EMPTY)
		{
			if (i > 0 && map[i - 1][j] != WALL)
				exit_log(RED ERR_MAP_OPEN RST);
			while (i < map_height - 1 && map[i][j] == EMPTY)
				i++;
			if (map[i][j] && map[i][j] != WALL && map[i][j] != EMPTY)
				exit_log(RED ERR_MAP_OPEN RST);
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
	if (players != 1)
		exit_log(RED ERR_PLR RST);
}
