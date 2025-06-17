/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:14:57 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/17 22:10:39 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/*============================ MAP_DEFINITIONS ==============================*/
# define CORR '0'
# define WALL '1'
# define EMPTY ' '
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

/*============================= MAP_FUNCTIONS ===============================*/

void	map_checker(void);
int	check_right_wall(int i, int col);
int	right_wall_right_line(int line, int col);
int	right_wall_left_line(int line, int col);
int	check_left_wall(int i, int col);
int	left_wall_right_line(int line, int col);
int	left_wall_left_line(int line, int col);

#endif
