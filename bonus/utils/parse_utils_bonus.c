/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:37:57 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:38:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	text_dist(char **arr, char *line)
{
	if (!ft_strncmp("SO", arr[0], ft_strlen(arr[0]))
		&& !g()->textures->south.img)
		return (assign_img(&g()->textures->south, arr, line));
	else if (!ft_strncmp("NO", arr[0], ft_strlen(arr[0]))
		&& !g()->textures->north.img)
		return (assign_img(&g()->textures->north, arr, line));
	else if (!ft_strncmp("WE", arr[0], ft_strlen(arr[0]))
		&& !g()->textures->west.img)
		return (assign_img(&g()->textures->west, arr, line));
	else if (!ft_strncmp("EA", arr[0], ft_strlen(arr[0]))
		&& !g()->textures->east.img)
		return (assign_img(&g()->textures->east, arr, line));
	return (0);
}

void	save_line(char *line, int line_size, int row)
{
	g()->map.map_data[row] = malloc(line_size);
	if (g()->map.map_data[row] == NULL)
	{
		free(line);
		exit_log(RED ERR_MEM RST);
	}
	ft_strlcpy(g()->map.map_data[row], line, line_size);
}

int	check_id(char *line)
{
	char	**arr;

	arr = ft_alt_split(line, ' ');
	if (!arr)
	{
		free(line);
		exit_log(RED ERR_MEM RST);
	}
	if (array_size(arr) != 2)
	{
		clear_arr(arr);
		return (0);
	}
	if (!ft_strncmp("SO", arr[0], ft_strlen(arr[0]))
		|| !ft_strncmp("NO", arr[0], ft_strlen(arr[0]))
		|| !ft_strncmp("WE", arr[0], ft_strlen(arr[0]))
		|| !ft_strncmp("EA", arr[0], ft_strlen(arr[0]))
		|| !ft_strncmp("C", arr[0], ft_strlen(arr[0]))
		|| !ft_strncmp("F", arr[0], ft_strlen(arr[0])))
	{
		clear_arr(arr);
		return (1);
	}
	clear_arr(arr);
	return (0);
}
