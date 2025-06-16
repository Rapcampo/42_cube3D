/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   $dda.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:54 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/16 11:47:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	verline(t_dda *dda, int y0, int y1, int color);
static int	get_tex_x(t_dda *dda, t_data *tex);
static void	get_tex_y(t_dda *dda, t_data *tex, t_point *tp, t_point *xsye);

static int	get_tex_x(t_dda *dda, t_data *tex)
{
	const t_fpoint	ppos = g()->player.pos;
	double	wallx;
	int		tpx;

	if (dda->side == 0)
		wallx = ppos.y + dda->wdist * dda->ray.y;
	else
		wallx = ppos.x + dda->wdist * dda->ray.x;
	wallx -= floor(wallx);
	tpx = trunc(wallx * (double)tex->width);
	if ((dda->side == 0 && dda->ray.x < 0) ||
		(dda->side == 1 && dda->ray.y > 0))
		tpx = tex->width - tpx - 1;
	return (tpx);
}

static void	get_tex_y(t_dda *dda, t_data *tex, t_point *tp, t_point *xsye)
{
	const int	lh = g()->frame.height / dda->wdist;
	int	i;
	int	color;
	int	factor;

	i = xsye->x;
	while (i < xsye->y)
	{
		tp->y = (int)((i + dda->offset - xsye->x) * tex->height / lh);
		color = 0;
		if (tp->y >= 0 && tp->y < tex->height)
		{
			factor = (tp->y * tex->ll + tp->x * (tex->bpp >> 3));
			color = *(int *)(tex->addr + factor);
		}
		pixel_put(&g()->frame, dda->x, i++, darken(dda->side, color));
	}
}

void	raydraw(t_dda *dda, t_data *tex)
{
	const int	h = g()->frame.height;
	int		line_height;
	t_point	xsye;
	t_point	tp;

	line_height = (int)(h / dda->wdist);
	xsye.x = fmax(-(line_height >> 1) + (h >> 1), 0);
	xsye.y = fmin((line_height >> 1) + (h >> 1), h);
	if (xsye.y >= h)
		xsye.y = h - 1;
	if (xsye.x == 0)
		dda->offset = -((-line_height >> 1) + (h >> 1));
	tp.x = get_tex_x(dda, tex);
	get_tex_y(dda, tex, &tp, &xsye);
}

/*void	verline(t_dda *dda, int y0, int y1, int color)
{
	t_data *frame;

	frame = &g()->frame;
	if (y0 > y1)
	{
		y0 ^= y1;
		y1 ^= y0;
		y0 ^= y1;
	}
	if (y0 < 0)
		y0 = 0;
	else if (y0 >= frame->height)
		y1 = frame->height;
	while (y0 < y1)
		pixel_put(frame, dda->x, y0++, darken(dda->side, color));
}*/
