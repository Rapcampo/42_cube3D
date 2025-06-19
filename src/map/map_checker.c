/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:34 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/19 12:05:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline int	*check_line_limits(char *line, int *vert)
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
			if (vert)
				free(vert);
			free(map_info);
			exit_log("Error: Invalid map (open)\n");
		}
	}
	map_info[1] = j - 1;
	return (map_info);
}

void	map_checker(void)
{
	int	*bot_vert;
	int	i[2];
	int	*j;

	bot_vert = check_line_limits(g()->map.map_data[g()->map.height - 1], NULL);
	j = check_line_limits(g()->map.map_data[0], bot_vert);
	i[0] = check_left_wall(0, j[0], j, bot_vert);
	i[1] = check_right_wall(0, j[1], j, bot_vert);
	while (i[0] < g()->map.height - 1 || i[1] < g()->map.height - 1)
	{
		if (i[0] < 0)
		{
			i[0] *= -1;
			j[0] = left_wall_left_line(i[0], j[0], j, bot_vert);
		}
		else if (i[0] < g()->map.height - 1)
			j[0] = left_wall_right_line(i[0], j[0], j, bot_vert);
		if (i[1] < 0)
		{
			i[1] *= -1;
			j[1] = right_wall_left_line(i[1], j[1], j, bot_vert);
		}
		else if (i[1] < g()->map.height - 1)
			j[1] = right_wall_right_line(i[1], j[1], j, bot_vert);
		if (i[0] < g()->map.height - 1)
			i[0] = check_left_wall(i[0], j[0], j, bot_vert);
		if (i[1] < g()->map.height - 1)
			i[1] = check_right_wall(i[1], j[1], j, bot_vert);
	}
	if (j[0] != bot_vert[0] || j[1] != bot_vert[1])
	{
		free(j);
		free(bot_vert);
		exit_log("Error: Invalid map (open)\n");
	}
	free(j);
	free(bot_vert);
	find_player();
}
