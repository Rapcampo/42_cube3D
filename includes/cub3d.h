/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:22:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/07 22:05:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*============================ Basic Libraries ===============================*/

# include "libft.h"
# include "Player.h"
# include "utils.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <mlx.h>

# include <math.h>
//# define __USE_MISC

# define WIDTH 800
# define HEIGHT 600

/*=========================== main game struct ===============================*/

typedef struct s_mlx
{
	void	*ptr;
	void	*mlx_win;
	char	*name;
	int		width;
	int		height;
}	t_mlx;

//acessed through g() function;
typedef struct s_game
{
	t_player	player;
	t_mlx		mlx;
	int			debug;
//	t_assets	*assets;
}	t_game;

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
	KEYLIFT_MASK	= (1L << 1),
	SUBNOTE_MASK	= (1L << 17)
}	t_mask;

typedef enum e_event
{
	E_kEYPRESS	= 2,
	E_KEYLIFT	= 3,
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

/*============================= struct access ================================*/

t_game	*g(void);

/*============================= struct access ================================*/

int		event_keypress(int keycode);
int		clean_exit();
int		output_game();

#endif
