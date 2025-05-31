#include "../../includes/cub3d.h"

// TODO: Confirm file names
short	**invalid_map_array(char *file)
{
	if (ft_strcmp(file, "../../maps/invalid/42.cub") == 0)
		short	map[][] = {{
			'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', 'N', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};
	else if (ft_strcmp(file, "../../maps/invalid/basic.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/big_map.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/corridor.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/different_order.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/double_extension.cub.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/some_weird_stuff.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/space_between_digits.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/spaces_after_path.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/spaces_end.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/spaces_end2.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/spaces_start.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/spaces_start2.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/subject.cub") == 0)
	else if (ft_strcmp(file, "../../maps/invalid/valid_hole.cub") == 0)
	return (map);
}
