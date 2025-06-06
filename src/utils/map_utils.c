/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:33:23 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/24 22:02:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

short	**create_map(size_t col)
{
	short	**map;

	map = malloc(sizeof(short *) * 2);
	if (map == NULL)
		exit_log("Error: Memory allocation error\n");	
	*map = malloc(sizeof(short) * (col + 1));
	if (*map == NULL)
	{
		free(map);
		exit_log("Error: Memory allocation error\n");	
	}
	ft_bzero(*map, sizeof(short) * (col + 1));
	*(map + 1) = NULL;
	return (map);
}

short	*create_map_line(size_t col)
{
	short	*line;

	line = malloc(sizeof(short) * (col + 1));
	if (line == NULL)
		exit_log("Error: Memory allocation error\n");
	ft_bzero(line, sizeof(short) * (col + 1));
	return (line);
}

short	**extend_map(size_t nb_lines, short **map)
{
	short	**new_map;
	size_t	i;

	new_map = malloc(sizeof(short *) * (nb_lines + 3));
	if (new_map == NULL)
		exit_log("Error: Memory allocation error\n");	
	i = -1;
	while (map[++i] != NULL)
		new_map[i] = map[i];
	while (i < nb_lines + 3)
		new_map[i++] = NULL;
	free(map);
	return (new_map);
}

size_t	map_size(short **map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (-1);
	while (map[i] != NULL)
		i++;
	return (i);
}
