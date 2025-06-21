/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:16:06 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/21 15:23:28 by tialbert         ###   ########.fr       */
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
	}
	g()->textures->north.img = NULL;
	g()->textures->north.addr = NULL;
	g()->textures->south.img = NULL;
	g()->textures->south.addr = NULL;
	g()->textures->west.img = NULL;
	g()->textures->west.addr = NULL;
	g()->textures->east.img = NULL;
	g()->textures->east.addr = NULL;
}
