/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:45:47 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/10 21:43:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	save_map(char *line, int row)
{
}

// TODO: Check if the ints to describe the colour can also be separated by spaces
// TODO: The strncmp function has been change to avoid past errors. Make sure it actually works correctly
static void	save_ceil_floor(char **arr)
{
	char	**num;

	num = ft_split(arr[1], ',');
	clear_arr(arr);
	// TODO: Create clearing function
	if (num == NULL)
		clear_all();
	if (ft_strncmp("C", arr[0], 1) == 0)
	{
		main_struct()->textures->ceil[0] = ft_atoi(num[0]);
		main_struct()->textures->ceil[1] = ft_atoi(num[1]);
		main_struct()->textures->ceil[2] = ft_atoi(num[2]);
	}
	else
	{
		main_struct()->textures->floor[0] = ft_atoi(num[0]);
		main_struct()->textures->floor[1] = ft_atoi(num[1]);
		main_struct()->textures->floor[2] = ft_atoi(num[2]);
	}
	clear_arr(num);
}

static void	save_texture(char *line)
{
	char	**arr;

	arr = ft_split(line, ' ');
	// TODO: Create clearing function
	if (arr == NULL)
		clear_all();
	if (ft_strncmp("SO", arr[0], 2) == 0)
		main_struct()->textures->south = arr[1];
	else if (ft_strncmp("NO", arr[0], 2) == 0)
		main_struct()->textures->north = arr[1];
	else if (ft_strncmp("WE", arr[0], 2) == 0)
		main_struct()->textures->west = arr[1];
	else if (ft_strncmp("EA", arr[0], 2) == 0)
		main_struct()->textures->east = arr[1];
	else
	{
		save_ceil_floor(arr);
		return ;
	}
	// arr[1] doesn't have to be freed because we will use that pointer
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

int	parsing(int	fd)
{
	char	*line;
	int		i;

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
