/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:00:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/22 10:55:57 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_log(RED ERR_FILE RST);
	return (fd);
}

// TODO: Verify if the extension check works properly with paths using more '.'
// Example: "../../maps/valid/42.cub" or "./maps/valid/42.cub"
int	check_file_exten(char *file)
{
	char	*ext;
	char	*dot_loc;

	ext = ".cub";
	dot_loc = ft_strrchr(file, '.');
	if (!dot_loc)
		exit_log(RED ERR_EXT RST);
	if (!ft_strncmp(dot_loc, ext, ft_strlen(ext)))
		return (open_file(file));
	exit_log(RED ERR_EXT RST);
	return (-1);
}
