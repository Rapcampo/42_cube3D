/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:37:57 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 22:12:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	text_dist(char **arr)
{
	if (ft_strncmp("SO", arr[0], 2) == 0 && !g()->textures->south.img)
	{
		assign_img(&g()->textures->south, arr[1]);
		return (1);
	}
	else if (ft_strncmp("NO", arr[0], 2) == 0 && !g()->textures->north.img)
	{
		assign_img(&g()->textures->north, arr[1]);
		return (1);
	}
	else if (ft_strncmp("WE", arr[0], 2) == 0 && !g()->textures->west.img)
	{
		assign_img(&g()->textures->west, arr[1]);
		return (1);
	}
	else if (ft_strncmp("EA", arr[0], 2) == 0 && !g()->textures->east.img)
	{
		assign_img(&g()->textures->east, arr[1]);
		return (1);
	}
	return (0);
}

void	save_line(char *line, int line_size, int row)
{
	g()->map.map_data[row] = malloc(line_size);
	if (g()->map.map_data[row] == NULL)
	{
		free(line);
		exit_log("Error: Memory allocation error\n");
	}
	ft_strlcpy(g()->map.map_data[row], line, line_size);
}
