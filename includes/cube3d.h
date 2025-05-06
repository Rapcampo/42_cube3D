/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:22:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/06 12:22:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/*============================ Basic Libraries ===============================*/

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

# include <math.h>
//# define __USE_MISC

/*================================= mlx keys =================================*/

# include "mlx.h"

typedef enum s_keys
{
	ESC = 65307,
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	Q = 113,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}	t_key;

typedef enum e_mask
{
	NOEVENT_MASK	= 0L,
	KEYPRESS_MASK	= (1L << 0),
	SUBNOTE_MASK	= (1L << 17)
}	t_mask;

typedef enum e_event
{
	E_kEYPRESS	= 2,
	E_DESTROY	= 17
}	t_event;

/*============================= Ansi colours =================================*/

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

#endif
