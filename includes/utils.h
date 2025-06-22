/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:17 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 21:31:34 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

struct	s_time;
struct	s_textures;

/*============================ UTIL_FUNCTIONS ===============================*/

int		check_file_exten(char *file);
void	get_time_delta(struct s_time *time);
int		darken(int side, int color);
void	clean_mem(char *msg, char **arr, char *str, char *path);

/*========================== MAP_UTIL_FUNCTIONS =============================*/
void	extend_map(size_t nb_lines);
void	create_map(void);

/*======================== TEXTURE_UTIL_FUNCTIONS ===========================*/
void	create_textures(void);
int		save_ceil(char *id, char **arr, struct s_textures *tex);
int		save_floor(char *id, char **arr, struct s_textures *tex);

/*======================== PLAYER_UTIL_FUNCTIONS ============================*/
int		check_chr(char c, int i, int j, int *players);

/*========================= ARRAY_UTIL_FUNCTIONS ============================*/
size_t	array_size(char **arr);

/*========================= PARSE_UTIL_FUNCTIONS ============================*/
int		text_dist(char **arr, char *line);
void	save_line(char *line, int line_size, int row);
int		check_id(char *line);

/*========================= SPLIT_UTIL_FUNCTIONS ============================*/
char	**ft_alt_split(const char *s, char c);

#endif
