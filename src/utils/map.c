/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:37:55 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/23 18:02:14 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	temp_map(t_map *map)
{
	const int size = 8;
	const int imap[] = {	1, 1, 1, 1, 1, 1, 1, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 1,
							1, 1, 1, 1, 1, 1, 1, 1};
	const size_t	map_size = sizeof(imap) / sizeof(int);
	int *const		map_data = ft_calloc(map_size, sizeof(int));

	if (!map_data)
		return (-1);
	map->map_data = map_data;
	map->height = size;
	map->width = size;
	return (0);
}
