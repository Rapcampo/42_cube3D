/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:33:23 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 21:26:11 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_map(void)
{
	g()->map.height = 0;
	g()->map.map_data = malloc(sizeof(char *) * 2);
	if (g()->map.map_data == NULL)
		exit_log("Error: Memory allocation error\n");
	g()->map.map_data[0] = NULL;
	g()->map.map_data[1] = NULL;
}

void	extend_map(size_t nb_lines)
{
	char	**new_map;
	size_t	i;

	new_map = malloc(sizeof(char *) * (nb_lines + 3));
	if (new_map == NULL)
		exit_log("Error: Memory allocation error\n");
	i = -1;
	while (++i < nb_lines)
		new_map[i] = g()->map.map_data[i];
	while (i < nb_lines + 3)
		new_map[i++] = NULL;
	free(g()->map.map_data);
	g()->map.map_data = new_map;
}
