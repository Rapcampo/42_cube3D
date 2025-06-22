/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:00:37 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 17:58:54 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "engine.h"

typedef struct s_textures
{
	t_data	north;
	t_data	south;
	t_data	east;
	t_data	west;
	int		floor[3];
	int		ceil[3];
}			t_textures;

int	assign_img(t_data *tex, char **img_arr, char *line);

#endif
