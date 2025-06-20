/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:44:16 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/20 21:50:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static inline char	*resize_line(char *line, int width)
{
	char	*new_line;
	int		i;

	new_line = malloc(width + 1);
	if (!new_line)
		exit_log("Error\n Memory allocation\n");
	bzero(new_line, width + 1);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	while (i < width)
		new_line[i++] = EMPTY;
	free(line);
	return (new_line);
}

void	resize_map(void)
{
	char	**map;
	size_t	map_width;

	map = g()->map.map_data;
	map_width = g()->map.width;
	while (*map)
	{
		if (ft_strlen(*map) < map_width)
			*map = resize_line(*map, map_width);
		map++;
	}
}
