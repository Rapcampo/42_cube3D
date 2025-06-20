/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:45:47 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/20 15:43:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	save_map(char *line, int row)
{
	int		line_size;
	char	*new_line_char;

	if (g()->map.height == 0)
		create_map();
	else if (g()->map.height % 2 != 0)
		extend_map(g()->map.height);
	line_size = ft_strlen(line);
	new_line_char = ft_strchr(line, '\n');
	if (new_line_char)
	{
		g()->map.map_data[row] = malloc(line_size);
		if (g()->map.map_data[row] == NULL)
		{
			free(line);
			exit_log("Error: Memory allocation error\n");
		}
		// This removes the line break character from the line
		ft_strlcpy(g()->map.map_data[row], line, line_size);
	}
	else
	{
		g()->map.map_data[row] = malloc(line_size + 1);
		if (g()->map.map_data[row] == NULL)
		{
			free(line);
			exit_log("Error: Memory allocation error\n");
		}
		// This removes the line break character from the line
		ft_strlcpy(g()->map.map_data[row], line, line_size + 1);
	}
	if ((line_size - 1) > g()->map.width)
		g()->map.width = line_size - 1;
	g()->map.height++;
}

// TODO: The strncmp function has been changed to avoid past errors. Make sure it actually works correctly
static void	save_ceil_floor(char **arr, char *line)
{
	char	**num;

	num = ft_split(arr[1], ',');
	if (num == NULL)
		exit_log("Error: Memory allocation error\n");	
	if (array_size(num) != 3)
	{
		free(line);
		clear_arr(arr);
		clear_arr(num);
		exit_log("Error: Incorrect format for colours (floor and ceiling)\n");
	}
	if (ft_strncmp("C", arr[0], 1) == 0)
	{
		g()->textures->ceil[0] = ft_atoi(num[0]);
		g()->textures->ceil[1] = ft_atoi(num[1]);
		g()->textures->ceil[2] = ft_atoi(num[2]);
	}
	else if (ft_strncmp("F", arr[0], 1) == 0)
	{
		g()->textures->floor[0] = ft_atoi(num[0]);
		g()->textures->floor[1] = ft_atoi(num[1]);
		g()->textures->floor[2] = ft_atoi(num[2]);
	}
	clear_arr(num);
}

// TODO: Change function to save the texture in t_data (Raphael already has functions for that)
static int	save_texture(char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (arr == NULL)
		exit_log("Error: Memory allocation error\n");	
	if (array_size(arr) != 2)
	{
		free(line);
		clear_arr(arr);
		exit_log("Error: Texture information format is wrong\n");
	}
	if (ft_strncmp("SO", arr[0], 2) == 0 && !g()->textures->south)
		g()->textures->south = arr[1];
	else if (ft_strncmp("NO", arr[0], 2) == 0 && !g()->textures->north)
		g()->textures->north = arr[1];
	else if (ft_strncmp("WE", arr[0], 2) == 0 && !g()->textures->west)
		g()->textures->west = arr[1];
	else if (ft_strncmp("EA", arr[0], 2) == 0 && !g()->textures->east)
		g()->textures->east = arr[1];
	else if (arr[0][0] == 'F' || arr[0][0] == 'C')
	{
		save_ceil_floor(arr, line);
		clear_arr(arr);
		return (1);
	}
	else
	{
		clear_arr(arr);
		return (0);
	}
	// arr[1] doesn't have to be freed because we are using that pointer
	// in the texture struct
	free(arr[0]);
	free(arr);
	return (1);
}

static void	extract(char *line, int *nb)
{
	if (*line == '\n' && *nb > 6)
	{
		free(line);
		exit_log("Error: Invalid map (empty line)\n");
	}
	if (*line == '\n')
		return ;
	else if (*nb >= 6)
		save_map(line, (((*nb) / 6 - 1) * 6 + ((*nb) % 6)));
	else
	{
		*nb += save_texture(line);
		return ;
	}
	(*nb)++;
}

void	parsing(int	fd)
{
	char	*line;
	int		i;

	create_textures();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		extract(line, &i);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (i <= 6)
		exit_log("Error: Missing information on .cub file\n");
	resize_map();
}
