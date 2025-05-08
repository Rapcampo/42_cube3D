/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:23:58 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/08 22:18:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
//adding placeholder error message functions
//window initialization should be working!

int	output_game(void)
{
	return (0);
}

static void	loop_initializer(void)
{
	t_mlx	*mlx;

	mlx = &g()->mlx;
	mlx_hook(mlx->win, E_KEYPRESS, KEYPRESS_MASK, &event_keypress, g());
//	mlx_hook(&g()->mlx, E_KEYLIFT, KEYLIFT_MASK, &event_keylift, g());
	mlx_hook(mlx->win, E_DESTROY, SUBNOTE_MASK, &clean_exit, g());
	mlx_loop_hook(mlx->ptr, &output_game, g());
	mlx_loop(mlx->ptr);
}

static void	start_mlx_win(void)
{
	t_mlx	*mlx;

	mlx = &g()->mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit_log(RED ER_MLX_INIT RST);
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "cub3d");
	if (!mlx->win)
		exit_log(RED ER_MLX_WIN RST);
}

static void	init_game(void)
{
	ft_bzero(g(), sizeof(t_game));
	start_mlx_win();
	//need to load images here
	//need to load graphics here
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		exit_log(YLW WRNG_USE CLR BLU USE_FORMAT RST);
//	parsing(check_file_exten(argv[1]));
	init_game();
	loop_initializer();
	clean_exit();
}
