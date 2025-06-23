/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:00:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/23 22:19:42 by tialbert         ###   ########.fr       */
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

int	check_file_exten(char *file, char *ext, int opt)
{
	char	*dot_loc;

	dot_loc = ft_strrchr(file, '.');
	if (!dot_loc)
		exit_log(RED ERR_EXT RST);
	if (!ft_strncmp(dot_loc, ext, ft_strlen(ext)) && opt)
		return (open_file(file));
	else if (!ft_strncmp(dot_loc, ext, ft_strlen(ext)) && !opt)
		return (1);
	if (!opt)
		return (0);
	exit_log(RED ERR_EXT_C RST);
	return (-1);
}
