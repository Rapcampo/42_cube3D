/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:11:09 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/20 23:03:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_images(t_game *game, t_data *asset)
{
	mlx_destroy_image(game->mlx.ptr, asset->img);
}

void	destroy_map(void **map)
{
	int	i;

	i = -1;
	if (map[0] != NULL)
	{
		while (map[++i] != NULL)
			free(map[i]);
		free(map);
	}
}

static void	destroy_textures(t_game *game, t_textures *textures)
{
	if (textures->north.img)
		destroy_images(game, &textures->north);
	if (textures->south.img)
		destroy_images(game, &textures->south);
	if (textures->east.img)
		destroy_images(game, &textures->east);
	if (textures->west.img)
		destroy_images(game, &textures->west);
}

void	destroy_game(void)
{
	t_game	*game;

	game = g();
	if (!game)
		return ;
	if (game->map.map_data != 0)
		destroy_map((void **) game->map.map_data);
	if (game->frame.img != NULL)
		destroy_images(game, &game->frame);
	if (game->textures)
		destroy_textures(game, game->textures);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (game->mlx.ptr)
	{
		mlx_do_key_autorepeaton(g()->mlx.ptr);
		mlx_destroy_display(game->mlx.ptr);
	}
	free(game->mlx.ptr);
}

int	clean_exit(void)
{
	destroy_game();
	exit(0);
}
