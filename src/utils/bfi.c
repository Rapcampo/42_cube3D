/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:43:05 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/29 16:45:18 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	bfi(t_data *data)
{
	int	h;
	int	w;

	h = -1;
	w = -1;
	while (++h < HEIGHT)
	{
		while (w++ < WIDTH)
			pixel_put(data, 0 + w, 0 + h, 0x00);
		w = -1;
	}
}
