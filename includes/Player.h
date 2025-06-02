/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:37:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/02 14:06:20 by rapcampo         ###   ########.fr       */
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
	float x;
	float y;
}	t_fpoint;

typedef struct s_player
{
	t_fpoint	pos;
	t_fpoint	dir;
	t_fpoint	plane;
}			t_player;

typedef struct s_dda
{
	t_point		player;
	t_point		delta;
	int 		steps;
	t_fpoint	fcord;
	t_fpoint	inc;
}	t_dda;

#endif
