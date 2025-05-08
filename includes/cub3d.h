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

/*============================ Custom Libraries ==============================*/

# include "memory.h"
# include "libft.h"
# include "Player.h"
# include "utils.h"
# include "macro.h"

/*=========================== main game struct ===============================*/

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
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

// enum for event hook mask
// defined in x11/x.h 
// close mask is for substructureNotifyMask for creation or destruction of win
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


/*============================= struct access ================================*/

t_game	*g(void);

/*============================= struct access ================================*/

int		event_keypress(int keycode);
int		clean_exit();
int		output_game();

#endif
