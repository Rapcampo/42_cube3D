/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:25:22 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/08 11:33:13 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*============================= Usage Msg ====================================*/

# define WRNG_USE "Insuficient Arguments for cub3d!\n"
# define USE_FORMAT "Usage: ./cub3d [path_to_map]\n"

/*============================= Error Logs ===================================*/

# define ER_MLX_INIT "Error: mlx_init failed!"
# define ER_MLX_WIN "Error: mlx_win failed to initialize!"

/*============================= Ansi colours =================================*/

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

#endif
