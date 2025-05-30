/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:37:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/07 21:44:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;
	float	px;
	float	py;
	char	rot;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		ceil[3];
}			t_player;


#endif
