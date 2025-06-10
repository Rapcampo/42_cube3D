/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:45:47 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/07 09:07:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: Allocate memory for map array and define the types of units in the map
// TODO: Find the best way to allocate the memory
static void	save_map(char *line, int row)
{
	int		col;
	size_t	size;

	col = 0;
	size = map_size(g()->map);
	if (size == 0)
		g()->map = create_map(ft_strlen(line));
	else if (size % 2 != 0)
		g()->map = extend_map(size, g()->map);
	g()->map[row] = create_map_line(ft_strlen(line));
	while (line && *line != '\n')
	{
		if (*line == ' ')
			g()->map[row][col] = EMPTY;
		else
			g()->map[row][col] = *line;
		col++;
	}
}

// TODO: Check if the ints to describe the colour can also be separated by spaces
// TODO: The strncmp function has been changed to avoid past errors. Make sure it actually works correctly
static void	save_ceil_floor(char **arr)
{
	char	**num;

	num = ft_split(arr[1], ',');
	clear_arr((void **) arr);
	// TODO: Create clearing function
	if (num == NULL)
		exit_log("Error: Memory allocation error\n");	
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
	else
		exit_log("Error: Incorrect scene description file\n");
	clear_arr((void **) num);
}

static void	save_texture(char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (arr == NULL)
		exit_log("Error: Memory allocation error\n");	
	if (ft_strncmp("SO", arr[0], 2) == 0)
		g()->textures->south = arr[1];
	else if (ft_strncmp("NO", arr[0], 2) == 0)
		g()->textures->north = arr[1];
	else if (ft_strncmp("WE", arr[0], 2) == 0)
		g()->textures->west = arr[1];
	else if (ft_strncmp("EA", arr[0], 2) == 0)
		g()->textures->east = arr[1];
	else
	{
		save_ceil_floor(arr);
		return ;
	}
	// arr[1] doesn't have to be freed because are using that pointer
	// in the texture struct
	free(arr[0]);
	free(arr);
}

static void	extract(char *line, int *nb)
{
	if (*line == '\n')
		return ;
	else if (*nb >= 6)
		save_map(line, *nb / 6 + *nb % 6 - 1);
	else
		save_texture(line);
	(*nb)++;
}

void	parsing(int	fd)
{
	char	*line;
	int		i;

	if (g()->textures == NULL)
	{
		g()->textures = malloc(sizeof(t_textures));
		if (g()->textures == NULL)
			exit_log("Error: Memory allocation error\n");
	}
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		extract(line, &i);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
