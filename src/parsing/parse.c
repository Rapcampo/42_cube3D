/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:45:47 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:29:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ft_strlcpy functions remove the line break character from the line
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
		save_line(line, line_size, row);
	else
		save_line(line, line_size + 1, row);
	if ((line_size - 1) > g()->map.width)
		g()->map.width = line_size - 1;
	g()->map.height++;
}

static void	save_ceil_floor(char **arr, char *line)
{
	char	**num;

	num = ft_split(arr[1], ',');
	if (num == NULL)
		exit_log(RED ERR_MEM RST);
	if (array_size(num) != 3)
	{
		clear_arr(num);
		clean_mem(RED ERR_COL RST, arr, line, NULL);
	}
	if (!save_ceil(arr[0], num, g()->textures))
	{
		clear_arr(num);
		clean_mem(RED ERR_COL RST, arr, line, NULL);
	}
	if (!save_floor(arr[0], num, g()->textures))
	{
		clear_arr(num);
		clean_mem(RED ERR_COL RST, arr, line, NULL);
	}
	clear_arr(num);
}

static int	save_texture(char *line)
{
	char	**arr;

	arr = ft_alt_split(line, ' ');
	if (arr == NULL)
		exit_log(RED ERR_MEM RST);
	if (array_size(arr) != 2)
		clean_mem(RED ERR_TEX RST, arr, line, NULL);
	if (!ft_strncmp(arr[0], "F", ft_strlen(arr[0]))
		|| !ft_strncmp(arr[0], "C", ft_strlen(arr[0])))
	{
		save_ceil_floor(arr, line);
		clear_arr(arr);
		return (1);
	}
	else if (text_dist(arr, line))
	{
		clear_arr(arr);
		return (1);
	}
	clear_arr(arr);
	free(line);
	exit_log(RED ERR_INV_LINE RST);
	return (0);
}

static void	extract(char *line, int *nb)
{
	if (check_id(line) && *nb >= 6)
	{
		free(line);
		exit_log(RED ERR_TEX_REP RST);
	}
	if (*line == '\n' && *nb > 6)
	{
		free(line);
		exit_log(RED ERR_MAP_LINE RST);
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

void	parsing(int fd)
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
		exit_log(RED ERR_MISS RST);
	resize_map();
}
