/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:40:02 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/21 15:44:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: Clean up the removing of the line break from the img_path
void	assign_img(t_data *tex, char *img_path)
{
	char	*path;
	t_mlx	*mlx;

	if (img_path == NULL)
		exit_log(RED ERR_PATH RST);
	path = malloc(ft_strlen(img_path));
	if (!path)
		exit_log("Error\nMemory allocation\n");
	ft_strlcpy(path, img_path, ft_strlen(img_path));
	mlx = &g()->mlx;
	tex->img = mlx_xpm_file_to_image(mlx->ptr,
			path, &tex->width, &tex->height);
	if (tex->img == NULL || tex->height == 0 || tex->width == 0)
		exit_log(RED ERR_OPEN RST);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->ll, &tex->endian);
	if (tex->addr == NULL)
		exit_log(RED ERR_ADDR RST);
	free(path);
}
