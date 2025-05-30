/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:04:17 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/30 19:15:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//todo: dda propper implementation
//todo: 


void	raycaster(void)
{
	t_dda	dda;

	ft_bzero(&dda, sizeof(t_dda));
	dda.x = 0;
	while (dda.x < g()->frame.width)
	{
		dda = cast_ray(dda.x);
		ray_touch(&dda);
	}
}
