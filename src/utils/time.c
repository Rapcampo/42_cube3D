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

void	get_time_delta(struct s_time *time)
{
	static struct timeval c_tv = {0};
	static struct timeval p_tv = {0};
	
	if (gettimeofday(&c_tv, NULL) < 0)
		exit_log(RED ERR_TIME RST);
	time->delta = (c_tv.tv_sec - p_tv.tv_sec) + (c_tv.tv_usec - p_tv.tv_usec)
		/ 1000000.0;
	if (time->delta > 0)
		time->fps = 1.0 / time->delta;
	else
		time->fps = 0;
	p_tv = c_tv;
}
