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
	const int imap[8][8] = {
		{P, P, P, P, P, P, P, P},
		{P, V, V, V, V, P, V, P},
		{P, V, V, P, P, P, V, P},
		{P, V, V, V, V, V, V, P},
		{P, V, V, P, V, V, V, P},
		{P, V, P, V, V, P, V, P},
		{P, V, P, V, V, V, V, P},
		{P, P, P, P, P, P, P, P}
	};
	const size_t	map_size = size * size;
	int **const		map_data = ft_calloc(8, sizeof(int*));
	int	i;

	i = -1;
	if (!map_data)
		return (-1);
	while (++i < 8)
	{
		map_data[i] = ft_calloc(8, sizeof(int));
		ft_memcpy(map_data[i], imap[i], sizeof(int) * 8);
	}
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
