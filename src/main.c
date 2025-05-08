/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:23:58 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/07 21:59:43 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
//adding placeholder error message functions
//window initialization should be working!

static void	loop_initializer(void)
{
	mlx_hook(&g()->mlx, E_kEYPRESS, KEYPRESS_MASK, &event_keypress, NULL);
	mlx_hook(&g()->mlx, E_KEYLIFT, KEYLIFT_MASK, &event_keypress, NULL);
	mlx_hook(&g()->mlx, E_DESTROY, SUBNOTE_MASK, &clean_exit, NULL);
	mlx_loop_hook(&g()->mlx, &output_game, NULL);
	mlx_loop(&g()->mlx);
}

static void	start_mlx_win(void)
{
	t_mlx	*mlx;

	mlx = &g()->mlx;
	mlx->ptr = mlx_init();
	if (!g()->mlx.mlx_win)
		ft_putstr_fd("mlx_init fail", 2), exit(1);
	mlx->mlx_win = mlx_new_window(g()->mlx.ptr, WIDTH, HEIGHT, "cub3d");
	if (!g()->mlx.mlx_win)
		ft_putstr_fd("mlx_window fail", 2), exit(1);
}

static void	init_game(void)
{
	ft_bzero(g(), sizeof(t_game));
	start_mlx_win();
	//need to load images here
	//need to load graphics here
	loop_initializer();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Not enough arguments!");
		exit(1);
	}
	check_file_exten(argv[1]);
	init_game();
//	clean_exit();
}
