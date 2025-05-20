/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/18 17:48:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/*============================ UTIL_FUNCTIONS ===============================*/

/*============================== FILE_UTILS =================================*/
int		check_file_exten(char *file);

/*============================== MAP_UTILS ==================================*/
short	**create_map(size_t col);
short	*create_map_line(size_t col);
short	**extend_map(size_t nb_lines, short **map);
size_t	map_size(short **map);

#endif
