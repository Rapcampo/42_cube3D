/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:34 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/10 16:15:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: This would be the most basic version of the map checker (should be enough to test the rest, but to simple for real maps)
static inline char	*check_line(char *line, char *begin_end_map)
{
	size_t	i;
	size_t	line_size;
	char	*map_info;

	i = 0;
	line_size = ft_strlen(line);
	map_info = malloc(2);
	if (map_info == NULL)
		exit_log("Error: Memory allocation failed\n");
	bzero(map_info, 2);
	while (line[i] == EMPTY && i < line_size)
		i++;
	map_info[0] = (char) i;
	while (i < line_size)
	{
		if (line[i++] != WALL)
			exit_log("Error: Invalid map\n");
	}
	map_info[1] = (char) i;
	free(begin_end_map);
	return (map_info);
}

void	map_checker(void)
{
	size_t	i;
	size_t	map_col_size;
	size_t	map_line_size;

	map_col_size = map_size(g()->map);
	i = 0;
	while (g()->map[0][i] != 0)
	{
		if (g()->map[0][i] != WALL || g()->map[map_col_size][i] != WALL)
			exit_log("Error: Invalid map\n");
	}
	map_line_size = i;
	i = 0;
	while (g()->map[i] != 0)
	{
		if (g()->map[i][0] != WALL || g()->map[i][map_line_size] != WALL)
			exit_log("Error: Invalid map\n");
	}
}
