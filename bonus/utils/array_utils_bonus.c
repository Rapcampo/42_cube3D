/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:18:45 by tialbert          #+#    #+#             */
/*   Updated: 2025/06/19 12:19:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	array_size(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}
