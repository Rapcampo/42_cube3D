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
void	ray_touch(t_dda *dda);
t_dda	cast_ray(int x);

t_dda	cast_ray(int x)
{
	const float	camx = (x << 1) / (float)g()->frame.width -1;	
	float		rayx = dirx + planex * camx;
	float		rayy = diry + planey * camx;
	double ddx = abs(1 / rayx);
	double ddy = abs(1 / rayy);
	int	step_x;
	int	step_y;
	double perpwalldist;
	int hit = 0;
	int side;
	int	mapx;
	int	mapy;
}

int	dda(t_dda *dda)
{
	int	i;
	//base of the algorythmn
	i = -1;
	dda->dx = dda->x0 - dda->x1;
	dda->dy = dda->y0 - dda->y1;
	if (abs(dx) > abs(dy))
		dda->steps = dda->dx;
	else
		dda->steps = dda->dy;
	dda->xinc = dda->dx / (float)dda->steps;
	dda->yinc = dda->dy / (float)dda->steps;
	dda->fx = dda->x0;
	dda->fy = dda->y0;
	while (++i <= dda->steps)
	{
		pixel_put(&g()->skybox.sky, round(dda->fx), round(dda->fy), 0x0000FF00);
		dda->fx += dda->xinc;
		dda->fy += dda->yinc;
	}
	return (0);
}

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
