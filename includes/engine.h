/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:27:19 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/10 19:28:15 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# define MOV_SPEED 2.5
# define ROT_SPEED 2.5

# ifdef DEBUG
# define CEILING 0x0087ceeb
# define FLOOR 0x00138510
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	endian;
	int	height;
	int	width;
}	t_data;

typedef struct s_dda
{
	int x;
	int	y;
	int dy;
	int dx;
	int steps;
	float fx;
	float fy;
	float xinc;
	float yinc;
}	t_dda;

typedef struct s_map
{
	t_data	sky;
//	t_data	floor;
	int		c_color;
	int		f_color;
}	t_map;

int		event_keypress(int keycode);
int		event_keylift(int keycode);
int		gameloop(void);
int		init_skybox(t_data *sky);
int		render_skybox(t_data *sky);
void	pixel_put(t_data *data, int x, int y, int color);

#endif
