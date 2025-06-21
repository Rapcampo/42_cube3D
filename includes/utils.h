/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 11:30:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

struct	s_time;

/*============================ UTIL_FUNCTIONS ===============================*/

int		check_file_exten(char *file);
void	get_time_delta(struct s_time *time);
int		darken(int side, int color);

/*========================== MAP_UTIL_FUNCTIONS =============================*/
void	extend_map(size_t nb_lines);
// short	*create_map_line(size_t col);
void	create_map(void);

/*======================== TEXTURE_UTIL_FUNCTIONS ===========================*/
void	create_textures(void);

/*======================== PLAYER_UTIL_FUNCTIONS ============================*/
// void	find_player(void);
int		check_chr(char c, int i, int j, int *players);

/*========================= ARRAY_UTIL_FUNCTIONS ============================*/
size_t	array_size(char **arr);

#endif
