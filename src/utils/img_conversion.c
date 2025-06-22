/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:40:02 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/22 17:59:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

inline void	clean_mem(char *msg, char **arr, char *str, char *path)
{
	if (path)
		free(path);
	if (str)
		free(str);
	if (arr)
		clear_arr(arr);
	exit_log(msg);
}

int	assign_img(t_data *tex, char **img_arr, char *line)
{
	char	*path;
	t_mlx	*mlx;

	if (img_arr[1] == NULL)
		clean_mem(RED ERR_PATH RST, img_arr, line, NULL);
	path = malloc(ft_strlen(img_arr[1]));
	if (!path)
		clean_mem(RED ERR_MEM RST, img_arr, line, NULL);
	ft_strlcpy(path, img_arr[1], ft_strlen(img_arr[1]));
	mlx = &g()->mlx;
	tex->img = mlx_xpm_file_to_image(mlx->ptr,
			path, &tex->width, &tex->height);
	if (tex->img == NULL || tex->height == 0 || tex->width == 0)
		clean_mem(RED ERR_OPEN RST, img_arr, line, path);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->ll, &tex->endian);
	if (tex->addr == NULL)
		clean_mem(RED ERR_ADDR RST, img_arr, line, path);
	free(path);
	return (1);
}
