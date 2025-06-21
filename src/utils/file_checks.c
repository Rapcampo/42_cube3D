/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:00:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 21:35:39 by tialbert         ###   ########.fr       */
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

// TODO: Verify if the extension check works properly with paths using more '.'
// Example: "../../maps/valid/42.cub" or "./maps/valid/42.cub"
int	check_file_exten(char *file)
{
	char	*ext;
	char	*dot_loc;

	ext = ".cub";
	dot_loc = ft_strrchr(file, '.');
	while (*dot_loc && *ext)
	{
		if (*(dot_loc++) != *(ext++))
		{
			printf("Error: Incorrect file type! \
				  Please, provide a '.cub' file\n");
			exit(1);
		}
	}
	if (!*dot_loc && !*ext)
		return (open_file(file));
	printf("Error: Incorrect file type! Please, provide a '.cub' file\n");
	exit(1);
}
