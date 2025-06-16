/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:34 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/16 22:50:28 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: Bug for when the next line is smaller than the current line
static inline int	check_right_wall(int i, int col)
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
			printf("col right\n");
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

static inline int	check_left_wall(int i, int col)
{
	int	line_size;

	while (i < g()->map.height - 1)
	{
		line_size = ft_strlen(g()->map.map_data[i]);
		if (g()->map.map_data[i][col] != WALL)
		{
			printf("col left\n");
			exit_log("Error: Invalid map (open)\n");
		}
		if (col < line_size - 1 && g()->map.map_data[i + 1][col] != WALL &&
			g()->map.map_data[i][col + 1] == WALL)
			return (i);
		else if (col > 0 && g()->map.map_data[i + 1][col] != WALL &&
			g()->map.map_data[i][col - 1] == WALL)
			return (-i);
		i++;
	}
	return (i);
}

// TODO: Write functions for horizontal checking on the left wall
static inline int	check_line_right(int line, int col)
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
			printf("right\n");
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_line_size - 1)
			return (col);
		col++;
	}
	return (col - 1);
}

static inline int	check_line_left(int line, int col)
{
	int	next_line_size;

	if (line < g()->map.height - 1)
		next_line_size = ft_strlen(g()->map.map_data[line + 1]);
	while (col >= 0 && line < g()->map.height - 1)
	{
		printf("col: %d\n", col);
		if (g()->map.map_data[line][col] != WALL)
		{
			printf("left\n");
			exit_log("Error: Invalid map (open)\n");
		}
		if (col == next_line_size - 1)
			return (col);
		col--;
	}
	return (col);
}

static inline int	*check_limit_lines(char *line)
{
	int	j;
	int	line_size;
	int	*map_info;

	j = 0;
	line_size = ft_strlen(line);
	map_info = malloc(sizeof(int) * 2);
	if (map_info == NULL)
		exit_log("Error: Memory allocation failed\n");
	bzero(map_info, 2);
	while (line[j] == EMPTY && j < line_size)
		j++;
	map_info[0] = j;
	while (j < line_size)
	{
		if (line[j++] != WALL)
		{
			free(map_info);
			printf("limits\n");
			exit_log("Error: Invalid map (open)\n");
		}
	}
	map_info[1] = j - 1;
	return (map_info);
}

void	map_checker(void)
{
	int	*bottom_corners;
	int	i[2];
	int	*j;

	bottom_corners = check_limit_lines(g()->map.map_data[g()->map.height - 1]);
	j = check_limit_lines(g()->map.map_data[0]);
	i[0] = check_left_wall(0, j[0]);
	i[1] = check_right_wall(0, j[1]);
	while (i[0] < g()->map.height - 1 || i[1] < g()->map.height - 1)
	{
		printf("i[0]: %d i[1]: %d\n", i[0], i[1]);
		if (i[0] < 0)
		{
			i[0] *= -1;
			j[0] = check_line_left(i[0], j[0]);
		}
		else if (i[0] < g()->map.height - 1)
			j[0] = check_line_right(i[0], j[0]);
		if (i[1] < 0)
		{
			i[1] *= -1;
			j[1] = check_line_left(i[1], j[1]);
		}
		else if (i[1] < g()->map.height - 1)
			j[1] = check_line_right(i[1], j[1]);
		printf("j[0]: %d j[1]: %d\n", j[0], j[1]);
		if (i[0] < g()->map.height - 1 && -i[0] < g()->map.height)
			i[0] = check_left_wall(i[0], j[0]);
		if (i[1] < g()->map.height - 1 && -i[1] < g()->map.height)
			i[1] = check_right_wall(i[1], j[1]);
	}
	printf("i[0]: %d i[1]: %d\n", i[0], i[1]);
	if (j[0] != bottom_corners[0] || j[1] != bottom_corners[1])
	{
		free(j);
		free(bottom_corners);
		exit_log("Error: Invalid map (open)\n");
	}
	free(j);
	free(bottom_corners);
}
