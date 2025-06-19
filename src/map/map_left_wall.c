/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_left_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:18 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/19 12:07:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline int	find_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] == EMPTY)
		i++;
	return (i);
}

// TODO: Test weird formats on the left wall
inline int	check_left_wall(int i, int col, int *j_vert, int *bot_vert)
{
	int	next_wall_col;

	if (i < g()->map.height - 1)
		next_wall_col = find_wall(g()->map.map_data[i + 1]);
	if (next_wall_col < col)
		return (-(i + 1));
	while (i < g()->map.height - 1)
	{
		next_wall_col = find_wall(g()->map.map_data[i + 1]);
		if (g()->map.map_data[i][col] != WALL)
		{
			if (j_vert)
				free(j_vert);
			if (bot_vert)
				free(bot_vert);
			exit_log("Error: Invalid map (open)\n");
		}
		if (next_wall_col > col)
			return (i);
		else if (next_wall_col < col)
			return (-(i + 1));
		i++;
		if (i < g()->map.height - 1)
			next_wall_col = find_wall(g()->map.map_data[i + 1]);
	}
	return (i);
}

inline int	left_wall_right_line(int line, int col, int *j_vert, int *bot_vert)
{
	int	line_size;
	int	next_wall_col;

	if (line == g()->map.height - 1)
		return (col);
	line_size = ft_strlen(g()->map.map_data[line]);
	if (line < g()->map.height - 1)
		next_wall_col = find_wall(g()->map.map_data[line + 1]);
	while (col < line_size)
	{
		if (g()->map.map_data[line][col] != WALL)
		{
			if (j_vert)
				free(j_vert);
			if (bot_vert)
				free(bot_vert);
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_wall_col)
			return (col);
		col++;
	}
	return (col - 1);
}

inline int	left_wall_left_line(int line, int col, int *j_vert, int *bot_vert)
{
	int	next_wall_col;

	if (line == g()->map.height - 1)
		return (col);
	if (line < g()->map.height - 1)
		next_wall_col = find_wall(g()->map.map_data[line + 1]);
	while (col >= 0)
	{
		if (g()->map.map_data[line][col] != WALL)
		{
			if (j_vert)
				free(j_vert);
			if (bot_vert)
				free(bot_vert);
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_wall_col)
			return (col);
		col--;
	}
	return (col);
}
