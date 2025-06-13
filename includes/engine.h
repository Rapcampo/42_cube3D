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

# define MOV_SPEED 3 
# define ROT_SPEED 4

struct s_mlx;
struct s_game;
struct s_dda;

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

typedef struct s_map
{
	char	**map_data;
	int		map_size;
	int		width;
	int		height;
	int		c_color;
	int		f_color;
}	t_map;

int		event_keypress(int keycode, struct s_game *g);
int		event_keylift(int keycode, struct s_game *g);
int		init_frame(t_data *frame, struct s_mlx *mlx);
int		init_minimap(t_data *minimap, struct s_mlx *mlx, t_data *frame);
int		render_frame(t_data *frame);
void	render_mov(struct s_player *p);
void	render_rot(struct s_player *p);
void	pixel_put(t_data *data, int x, int y, int color);
int		map_coord(int x, int y);
void	raycaster(void);
void	put_player(int x, int y, t_data *frame, int color);
int		render_game(t_data *frame);
void	bfi(t_data *frame);
void	raydraw(struct s_dda *dda);
void	verline(int x, int y0, int y1, int color);

#endif
