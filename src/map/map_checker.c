/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:34 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/17 22:10:11 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (i[0] < 0)
		{
			i[0] *= -1;
			j[0] = left_wall_left_line(i[0], j[0]);
		}
		else if (i[0] < g()->map.height - 1)
			j[0] = left_wall_right_line(i[0], j[0]);
		if (i[1] < 0)
		{
			i[1] *= -1;
			j[1] = right_wall_left_line(i[1], j[1]);
		}
		else if (i[1] < g()->map.height - 1)
			j[1] = right_wall_right_line(i[1], j[1]);
		if (i[0] < g()->map.height - 1 && -i[0] < g()->map.height)
			i[0] = check_left_wall(i[0], j[0]);
		if (i[1] < g()->map.height - 1 && -i[1] < g()->map.height)
			i[1] = check_right_wall(i[1], j[1]);
	}
	if (j[0] != bottom_corners[0] || j[1] != bottom_corners[1])
	{
		free(j);
		free(bottom_corners);
		exit_log("Error: Invalid map (open)\n");
	}
	free(j);
	free(bottom_corners);
}
