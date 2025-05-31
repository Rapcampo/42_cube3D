#include "../../includes/cub3d.h"

short	**valid_map_array(char *file)
{
	if (ft_strcmp(file, "../../maps/valid/42.cub") == 0)
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
	else if (ft_strcmp(file, "../../maps/valid/basic.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/big_map.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/corridor.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/different_order.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/double_extension.cub.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/some_weird_stuff.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/space_between_digits.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/spaces_after_path.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/spaces_end.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/spaces_end2.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/spaces_start.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/spaces_start2.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/subject.cub") == 0)
	else if (ft_strcmp(file, "../../maps/valid/valid_hole.cub") == 0)
	return (map);
}
