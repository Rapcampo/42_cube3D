/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:37:55 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/23 18:11:31 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	temp_map(t_map *map)
{
	const int size = 8;
	const int imap[] = {	1, 1, 1, 1, 1, 1, 1, 1,
							1, 0, 0, 0, 0, 1, 0, 1,
							1, 0, 0, 1, 1, 1, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 2, 0, 0, 0, 1,
							1, 0, 1, 0, 0, 0, 0, 1,
							1, 0, 1, 0, 0, 0, 0, 1,
							1, 1, 1, 1, 1, 1, 1, 1};
	const size_t	map_size = sizeof(imap);
	int *const		map_data = ft_calloc(map_size, sizeof(int));

	if (!map_data)
		return (-1);
	ft_memcpy(map_data, imap, map_size);
	map->map_data = map_data;
	map->height = size;
	map->width = size;
	map->map_size = map_size;
	g()->player.x = 5.5;
	g()->player.y = 5.5;
	g()->player.dirx = 1.0;
	g()->player.py = 0.66;
	return (0);
}
