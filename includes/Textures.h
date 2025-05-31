/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:00:37 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/10 21:01:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct s_textures {
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		ceil[3];
}			t_textures;

#endif
