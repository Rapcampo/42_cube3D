/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:37:55 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/23 18:11:31 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_coord(int x, int y)
{
	if (x < 0 || x >= g()->map.width || y < 0 || y >= g()->map.height)
		return (-1);
	return (g()->map.map_data[y][x]);
}

void	set_player(t_player *p, t_point *pos, char dir)
{
	p->pos.x = pos->x;
	p->pos.y = pos->y;
	if (dir == 'N')
	{
		p->dir.y = -1;
		p->plane.x = 0.66;
	}
	else if (dir == 'S')
	{
		p->dir.y = 1;
		p->plane.x = -0.66;
	}
	else if (dir == 'E')
	{
		p->dir.x = 1;
		p->plane.y = 0.66;
	}
	else if (dir == 'W')
	{
		p->dir.x = -1;
		p->plane.y = -0.66;
	}
}

void	set_skybox(t_textures *tex)
{
	int	c;
	int	f;

	c = get_argb(0x00, tex->ceil[0], tex->ceil[1],tex->ceil[2]);
	f = get_argb(0x00, tex->floor[0], tex->floor[1],tex->floor[2]);
	g()->map.c_color = c;
	g()->map.f_color = f;
}

int	temp_map(t_map *map)
{
	const int size = 24;
	const char imap[24][24] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
	const size_t	map_size = size * size;
	char **	map_data = ft_calloc(size, sizeof(char*) + 1);
	int	i;
	t_point	pos;
	t_textures tex = {0};

	tex.ceil[0] = get_red(HEX_COB);
	tex.ceil[1] = get_green(HEX_COB);
	tex.ceil[2] = get_blue(HEX_COB);
	tex.floor[0] = get_red(HEX_GRN);
	tex.floor[1] = get_green(HEX_GRN);
	tex.floor[2] = get_blue(HEX_GRN);
	i = -1;
	if (!map_data)
		return (-1);
	while (++i < size)
	{
		map_data[i] = ft_calloc(size + 1, sizeof(char));
		ft_memcpy(map_data[i], imap[i], sizeof(char) * size);
	}
	map->map_data = map_data;
	map->height = size;
	map->width = size;
	map->map_size = map_size;
	pos.x = 12;
	pos.y = 12;
	set_skybox(&tex);
	set_player(&g()->player, &pos, 'S');
	return (0);
}
