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

# define MOV_SPEED 3.5
# define ROT_SPEED 3.5

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
	int		*map_data;
	int		map_size;
	int		width;
	int		height;
	t_data	east;
	t_data	west;
	t_data	north;
	t_data	south;
	int		c_color;
	int		f_color;
}	t_map;

int		event_keypress(int keycode);
int		event_keylift(int keycode);
int		gameloop(void);
int		init_frame(t_data *frame);
int		render_frame(t_data *frame);
void	render_mov();
void	render_rot();
void	pixel_put(t_data *data, int x, int y, int color);
void	bfi(t_data *data);

#endif
