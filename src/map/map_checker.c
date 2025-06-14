/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:34 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/14 11:26:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline int	check_col(int col)
{
	int	i;

	i = 0;
	while (i < g()->map.height)
	{
		if (g()->map.map_data[i][col] != WALL)
			exit_log("Error: Invalid map\n");
		if (col > 0 && g()->map.map_data[i][col - 1] == WALL)
			return (-i);
		else if (g()->map.map_data[i][col + 1] == WALL &&
				g()->map.map_data[i + 1][col] != WALL)
			return (i);
		i++;
	}
	return (i);
}

static inline int	check_line_right(int line, int col)
{
	int	j;

	j = (int) col;
	while (j < g()->map.width)
	{
		if (g()->map.map_data[line][j] != WALL)
			exit_log("Error: Invalid map\n");
		if (g()->map.map_data[line + 1][j] == WALL)
			return (j);
		j++;
	}
	return (j);
}

static inline int	check_line_left(int line, int col)
{
	int	j;

	j = col;
	while (j > 0)
	{
		if (g()->map.map_data[line][j] != WALL)
			exit_log("Error: Invalid map\n");
		if (g()->map.map_data[line + 1][j] == WALL)
			return (j);

		j--;
	}
	return (j);
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
			exit_log("Error: Invalid map\n");
	}
	map_info[1] = j;
	return (map_info);
}

// TODO: Change map saving functions
void	map_checker(void)
{
	int	*bottom_corners;
	int	i[2];
	int	*j;

	j = check_limit_lines(g()->map.map_data[0]);
	bottom_corners = check_limit_lines(g()->map.map_data[g()->map.height]);
	i[0] = check_col(j[0]);
	i[1] = check_col(j[1]);
	while (i[0] < g()->map.height || i[1] < g()->map.height)
	{
		if (i[0] < 0)
			j[0] = check_line_left(i[0], j[0]);
		else
			j[0] = check_line_right(i[0], j[0]);
		if (i[1] < 0)
			j[1] = check_line_left(i[1], j[1]);
		else
			j[1] = check_line_right(i[1], j[1]);
		if (i[0] < g()->map.height)
			i[0] = check_col(i[0]);
		if (i[1] < g()->map.height)
			i[1] = check_col(i[1]);
	}
	free(j);
	free(bottom_corners);
}

// void	map_checker(void)
// {
// 	size_t	i;
// 	size_t	map_col_size;
// 	size_t	map_line_size;

// 	map_col_size = map_size(g()->map);
// 	i = 0;
// 	while (g()->map[0][i] != 0)
// 	{
// 		if (g()->map[0][i] != WALL || g()->map[map_col_size][i] != WALL)
// 			exit_log("Error: Invalid map\n");
// 	}
// 	map_line_size = i;
// 	i = 0;
// 	while (g()->map[i] != 0)
// 	{
// 		if (g()->map[i][0] != WALL || g()->map[i][map_line_size] != WALL)
// 			exit_log("Error: Invalid map\n");
// 	}
// }
