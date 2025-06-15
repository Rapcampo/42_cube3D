/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:16:06 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/15 15:17:52 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_textures(void)
{
	if (g()->textures == NULL)
	{
		g()->textures = malloc(sizeof(t_textures));
		if (g()->textures == NULL)
			exit_log("Error: Memory allocation error\n");
		g()->textures->north = NULL;
		g()->textures->south = NULL;
		g()->textures->east = NULL;
		g()->textures->west = NULL;
	}
}
