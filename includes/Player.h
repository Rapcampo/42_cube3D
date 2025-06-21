/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:37:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 21:28:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fpoint
{
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_player
{
	t_fpoint	pos;
	t_fpoint	dir;
	t_fpoint	plane;
}			t_player;

typedef struct s_dda
{
	t_point		map;
	t_point		step;
	t_fpoint	ray;
	t_fpoint	delta;
	t_fpoint	sdist;
	int			side;
	int			x;
	int			touch;
	float		wdist;
	int			offset;
}	t_dda;

struct	s_data;
struct	s_map;
struct	s_game;

void	put_los(struct s_data *minimap, t_dda *dda,
			struct s_map *map, int print);

#endif
