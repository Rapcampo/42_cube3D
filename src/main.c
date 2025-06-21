/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:27:07 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/21 21:47:08 by tialbert         ###   ########.fr       */
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
	char		*fps;

	get_time_delta(&gm->time);
	printf("Current FPS: %f\r", gm->time.fps);
	fps = ft_itoa((int)gm->time.fps);
	if (framesave == 6)
	{
		render_game(&gm->frame);
		raycaster();
		render_frame(&gm->minimap);
		put_los(&gm->minimap, NULL, &gm->map, 1);
		framesave = 0;
	}
	framesave++;
	render_mov(&gm->player);
	render_rot(&gm->player);
	mlx_put_image_to_window(gm->mlx.ptr, gm->mlx.win, gm->frame.img, 0, 0);
	mlx_string_put(gm->mlx.ptr, gm->mlx.win,
		WIDTH - 50, HEIGHT - 30, HEX_WHT, fps);
	free(fps);
	return (0);
}
//todo: check later
//	mlx_hook(map->mlx_win, 6, 1L << 6, mouse_rotate_hook, map);

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

static void	init_game(t_game *g, char *file)
{
	t_mlx		*mlx;
	t_textures	tex;

	ft_bzero(&tex, sizeof(tex));
	mlx = &g->mlx;
	g->textures = &tex;
	start_mlx_win();
	parsing(check_file_exten(file));
	map_checker();
	set_skybox(g->textures);
	init_frame(&g->frame, mlx);
	init_minimap(&g->minimap, mlx, &g->frame);
	mlx_do_key_autorepeatoff(g->mlx.ptr);
	mlx_hook(mlx->win, E_KEYPRESS, KEYPRESS_MASK, &event_keypress, g);
	mlx_hook(mlx->win, E_KEYLIFT, KEYLIFT_MASK, &event_keylift, g);
	mlx_hook(mlx->win, E_DESTROY, SUBNOTE_MASK, &clean_exit, g);
	mlx_loop_hook(mlx->ptr, &gameloop, g);
	mlx_loop(mlx->ptr);
}
	//need to load images here

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		exit_log(YLW WRNG_USE CLR BLU USE_FORMAT RST);
	init_game(g(), argv[1]);
	clean_exit();
}
