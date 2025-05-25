#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_log("Wrong number of arguments\n");
	parsing(check_file_exten(argv[1]));
	check_map(argv[1]);
}
