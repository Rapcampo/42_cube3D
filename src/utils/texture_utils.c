/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:16:06 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:32:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_textures(void)
{
	g()->textures->north.img = NULL;
	g()->textures->north.addr = NULL;
	g()->textures->south.img = NULL;
	g()->textures->south.addr = NULL;
	g()->textures->west.img = NULL;
	g()->textures->west.addr = NULL;
	g()->textures->east.img = NULL;
	g()->textures->east.addr = NULL;
}

static inline int	check_colour(char *colour)
{
	int	i;

	i = 0;
	while (colour[i])
	{
		if (colour[i] != ' ' && !ft_isdigit(colour[i]) && colour[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	save_ceil(char *id, char **arr, t_textures *tex)
{
	if (ft_strncmp(id, "C", ft_strlen(id)))
	{
		if (!check_colour(arr[0]) || !check_colour(arr[1])
			|| !check_colour(arr[2]))
			return (0);
		tex->ceil[0] = ft_atoi(arr[0]);
		tex->ceil[1] = ft_atoi(arr[1]);
		tex->ceil[2] = ft_atoi(arr[2]);
		return (1);
	}
	return (1);
}

int	save_floor(char *id, char **arr, t_textures *tex)
{
	if (ft_strncmp(id, "F", ft_strlen(id)))
	{
		if (!check_colour(arr[0]) || !check_colour(arr[1])
			|| !check_colour(arr[2]))
			return (0);
		tex->floor[0] = ft_atoi(arr[0]);
		tex->floor[1] = ft_atoi(arr[1]);
		tex->floor[2] = ft_atoi(arr[2]);
		return (1);
	}
	return (1);
}
