/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:11:09 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/08 12:15:19 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_game(void)
{
	t_game *game;

	game = g();
	if (!game)
		return ;
//	if (game->map)
//		destroy_map(game->map);
//	if (game->assets)
//		destroy_images(game);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	if (game->mlx.ptr){
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
