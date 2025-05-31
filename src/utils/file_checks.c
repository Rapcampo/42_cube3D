/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:00:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/05/08 22:09:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(strerror(errno));
		exit(errno);
	}
	return (fd);
}

int	check_file_exten(char *file)
{
	char	*ext;
	char	*dot_loc;

	ext = ".cub";
	dot_loc = ft_strchr(file, '.');
	while (*dot_loc && *ext)
	{
		if (*(dot_loc++) != *(ext++))
		{
			printf("Incorrect file type! Please, provide a '.cub' file");
			exit(1);
		}
	}
	if (!*dot_loc && !*ext)
		return (open_file(file));
	printf("Incorrect file type! Please, provide a '.cub' file");
	exit(1);
}
