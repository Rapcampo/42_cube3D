/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:13:01 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/08 11:17:02 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//placeholder function for unsucessful events
void	exit_log(char *message)
{
	destroy_game();
	ft_putstr_fd(message, 2);
	exit(1);
}
