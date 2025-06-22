/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:25:22 by rapcampo          #+#    #+#             */
/*   Updated: 2025/06/22 20:33:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*============================= Usage Msg ====================================*/

# define WRNG_USE "Insuficient Arguments for cub3d!\n"
# define USE_FORMAT "Usage: ./cub3d [path_to_map]\n"

/*============================= Error Logs ===================================*/

# define ER_MLX_INIT "Error\nmlx_init failed!\n"
# define ER_MLX_WIN "Error\nmlx_win failed to initialize!\n"
# define ERR_TIME "Error\ngettimeofday failure\n"
# define ERR_PATH "Error\nImage path does not lead to a valid file\n"
# define ERR_OPEN "Error\nMLX could not access image file\n"
# define ERR_ADDR "Error\nImage address has not been correctly set!\n"
# define ERR_IMG "Error\nMLX could not create image file\n"
# define ERR_EXT "Error\nIncorrect file type! Provide a '.cub' file\n"
# define ERR_FILE "Error\nError opening map information file\n"
# define ERR_MEM "Error\nMemory allocation error\n"
# define ERR_COL "Error\nIncorrect format for colours (floor and ceiling)\n"
# define ERR_NEG_COL "Error\nNegative value in colour\n"
# define ERR_HIGH_COL "Error\nColour value too high\n"
# define ERR_TEX "Error\nTexture information format is wrong\n"
# define ERR_TEX_REP "Error\nIdentifier is repeated\n"
# define ERR_MAP_LINE "Error\nInvalid map (empty line)\n"
# define ERR_MAP_OPEN "Error\nInvalid map (open)\n"
# define ERR_MISS "Error\nMissing information on .cub file\n"
# define ERR_INV_CHR "Error\nInvalid character in map.\n"
# define ERR_PLR "Error\nWrong number of players\n"
# define ERR_INV_LINE "Error\nInvalid line in .cub file\n"

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

/*============================== Hex colours =================================*/

typedef enum s_hex
{
	HEX_RED = 0x00e6003a,
	HEX_BLK = 0x00,
	HEX_PRP = 0x004b0082,
	HEX_WHT = 0x00FFFFFF,
	HEX_COB = 0x00003888,
	HEX_TRN = 0xFF000000,
	HEX_GRN = 0x00003311,
	HEX_CRM = 0x00B22222
}	t_hex;

#endif
