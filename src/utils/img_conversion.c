/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:40:02 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/16 13:44:08 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_img(t_data *tex, char *img_path)
{
	t_mlx	*mlx;

	mlx = &g()->mlx;
	if (img_path == NULL)
		exit_log("Error: image path does not exist");
	tex->img = mlx_xpm_file_to_image(mlx->ptr,
			img_path, &tex->width, &tex->height);
	if (tex->img == NULL || tex->height == 0 || tex->width == 0)
		exit_log("Error: Could not access image file");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->ll, &tex->endian);
}
