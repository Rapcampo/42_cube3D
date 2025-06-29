/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:22:12 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/07 09:05:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*============================ Basic Libraries ===============================*/

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include "../mlx/mlx.h"
# include <math.h>

# define WIDTH 800 
# define HEIGHT	600

/*============================ Custom Libraries ==============================*/

# include "memory.h"
# include "libft.h"
# include "Player.h"
# include "Textures.h"
# include "utils.h"
# include "macro.h"
# include "engine.h"
# include "map.h"
# include "parse.h"

/*=========================== main game struct ===============================*/

//NOTE N = dirx = 0, diry = -1; S x = 0, y = 1; E x = 1, y = 0; W x = -1, y = 0
//NOTE plane N x = 0.66; S x = -0.66; E y = 0.66; W y = -0.66

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	char	*name;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_time
{
	double	fps;
	double	delta;
}	t_time;

//acessed through g() function;
typedef struct s_game
{
	t_player	player;
	t_mlx		mlx;
	t_textures	*textures;
	int			debug;
	t_map		map;
	t_data		frame;
	t_data		minimap;
	t_fpoint	cell;
	t_time		time;
	int			key[0xFF];
}	t_game;

/*================================= mlx keys =================================*/

//w = 0 a = 6 s = 3 d = 2 left = 4 right = 5

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
	E_KEYPRESS	= 2,
	E_KEYLIFT	= 3,
	E_DESTROY	= 17
}	t_event;

/*============================= struct access ================================*/

t_game		*g(void);
int			gameloop(t_game *gm);
void		set_skybox(t_textures *tex);
void		set_player(t_player *p, t_point *pos, char dir);

/*============================= game =========================================*/
int			get_red(int argb);
int			get_green(int argb);
int			get_blue(int argb);
int			get_argb(int t, int r, int g, int b);
int			temp_map(t_map *imap);
t_fpoint	scalling_factor(t_game *g, t_fpoint *scale);

#endif
