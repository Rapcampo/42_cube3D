/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:39:00 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/13 20:28:26 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_fps(void)
{
};

int	get_time_now(void)
{
	static struct timeval s_tv = {0};
	static struct timeval a_tv = {0};
	gettimeofday(&s_tv, NULL);

	

}
