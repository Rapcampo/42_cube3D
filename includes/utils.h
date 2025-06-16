/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/15 15:18:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/*============================ UTIL_FUNCTIONS ===============================*/

int		check_file_exten(char *file);
void	get_time_delta(void);

/*========================== MAP_UTIL_FUNCTIONS =============================*/
size_t	map_size(char **map);
void	extend_map(size_t nb_lines);
// short	*create_map_line(size_t col);
void	create_map(void);

/*======================== TEXTURE_UTIL_FUNCTIONS ===========================*/
void	create_textures(void);

#endif
