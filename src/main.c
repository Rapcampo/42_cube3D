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

//TODO:: need to put just one image composed of all elements to not get screen
//tear.
//TODO:: implement DDA algorythmn, compare with bresenhams.
//calculate movement rotation with cos and sin of x,y coordinates

int	gameloop(t_game *gm)
{
	static int	framesave;

	get_time_delta(&gm->time);
	if (framesave == 6)
	{
		printf("Current FPS: %f\r", gm->time.fps);
		render_game(&gm->frame);
		raycaster();
//		render_frame(&gm->minimap);
		framesave = 0;
	}
	framesave++;
	render_mov(&gm->player);
	render_rot(&gm->player);
	mlx_put_image_to_window(gm->mlx.ptr, gm->mlx.win, gm->frame.img, 0, 0);
	return (0);
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

static void	init_game(t_game *g)
{
	t_mlx	*mlx;

	mlx = &g->mlx;
	start_mlx_win();
	temp_map(&g->map);
	init_frame(&g->frame, mlx);
	init_minimap(&g->minimap, mlx, &g->frame);
	//need to load images here
//	set_skybox(&g->textures);
	mlx_do_key_autorepeatoff(g->mlx.ptr);
	mlx_hook(mlx->win, E_KEYPRESS, KEYPRESS_MASK, &event_keypress, g);
	mlx_hook(mlx->win, E_KEYLIFT, KEYLIFT_MASK, &event_keylift, g);
	mlx_hook(mlx->win, E_DESTROY, SUBNOTE_MASK, &clean_exit, g);
	mlx_loop_hook(mlx->ptr, &gameloop, g);
	mlx_loop(mlx->ptr);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		exit_log(YLW WRNG_USE CLR BLU USE_FORMAT RST);
	//	check_file_exten(argv[1]);
	init_game(g());
	clean_exit();
}
