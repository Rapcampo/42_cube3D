/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_right_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:20:35 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/17 22:23:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

inline int	check_right_wall(int i, int col)
{
	int	line_size;
	int	next_line_size;

	line_size = ft_strlen(g()->map.map_data[i]);
	if (i < g()->map.height - 1)
		next_line_size = ft_strlen(g()->map.map_data[i + 1]);
	if (next_line_size < line_size)
		return (-(i + 1));
	while (i < g()->map.height - 1)
	{
		if (col < line_size - 1 && g()->map.map_data[i][col] != WALL)
		{
			exit_log("Error: Invalid map (open)\n");
		}
		if (next_line_size > line_size)
			return (i + 1);
		else if (next_line_size < line_size)
			return (-i);
		i++;
		line_size = next_line_size;
		if (i < g()->map.height - 1)
			next_line_size = ft_strlen(g()->map.map_data[i + 1]);
	}
	return (i);
}

inline int	right_wall_right_line(int line, int col)
{
	int	line_size;
	int	next_line_size;

	if (line == g()->map.height - 1)
		return (col);
	line_size = ft_strlen(g()->map.map_data[line]);
	if (line < g()->map.height - 1)
		next_line_size = ft_strlen(g()->map.map_data[line + 1]);
	while (col < line_size)
	{
		if (g()->map.map_data[line][col] != WALL)
		{
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_line_size - 1)
			return (col);
		col++;
	}
	return (col - 1);
}

inline int	right_wall_left_line(int line, int col)
{
	int	next_line_size;

	if (line < g()->map.height - 1)
		next_line_size = ft_strlen(g()->map.map_data[line + 1]);
	while (col >= 0 && line < g()->map.height - 1)
	{
		if (g()->map.map_data[line][col] != WALL)
		{
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_line_size - 1)
			return (col);
		col--;
	}
	return (col);;
}
