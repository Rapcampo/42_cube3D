#include "../../includes/cub3d.h"
#include "./tests_include/include.h"

// static void	cmp_arr(short **arr)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (g()->map[i])
// 	{
// 		j = 0;
// 		while (g()->map[i][j])
// 		{
// 			if (g()->map[i][j] != arr[i][j])
// 			{
// 				ft_printf("Real map (row: %i; col: %i): %i\n", i, j, arr[i][j]);
// 				ft_printf("Saved map (row: %i; col: %i): %i\n", i, j, g()->map[i][j]);
// 				assert(g()->map[i][j] == arr[i][j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
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

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_log("Wrong number of arguments\n");
	start_mlx_win();
	parsing(check_file_exten(argv[1]));
	// if (ft_strcmp(argv[1], "../../valid/") == 0)
	// 	cmp_arr(valid_map_array(argv[1]));
	// else
	// 	cmp_arr(invalid_map_array(argv[1]));
	map_checker();
	clean_exit();
}
