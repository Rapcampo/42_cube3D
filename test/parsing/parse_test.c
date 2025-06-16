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

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_log("Wrong number of arguments\n");
	parsing(check_file_exten(argv[1]));
	// if (ft_strcmp(argv[1], "../../valid/") == 0)
	// 	cmp_arr(valid_map_array(argv[1]));
	// else
	// 	cmp_arr(invalid_map_array(argv[1]));
	map_checker();
	clean_exit();
}
