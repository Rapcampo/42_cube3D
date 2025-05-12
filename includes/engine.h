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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	endian;
}	t_data;

typedef struct s_box
{
	t_data	sky;
	t_data	floor;
}	t_box;

int		event_keypress(int keycode);
int		event_keylift(int keycode);
int		output_game(void);
int		init_skybox(t_data *sky, t_data *floor);

#endif
