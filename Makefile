# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 13:52:55 by rapcampo          #+#    #+#              #
#    Updated: 2025/06/22 20:51:33 by tialbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Files ======================================

NAME	= cub3D
BONUS	= cub3D_bonus
SOURCE	= $(SOURCE_DIR)
PARSER	= parse.c resize_map.c
ENGINE	= key_events.c screen_output.c pixel_draw.c raycaster.c raydraw.c \
		  colours.c
MEMORY	= fail_exit.c clean_exit.c clean_array.c
UTILS	= global.c time.c map.c img_conversion.c file_checks.c map_utils.c \
		  texture_utils.c find_player.c array_utils.c parse_utils.c \
		  ft_alt_split.c
MAP		= map_checker.c
BPARSER	= parse_bonus.c resize_map_bonus.c
BENGINE	= key_events_bonus.c screen_output_bonus.c pixel_draw_bonus.c \
		  raycaster_bonus.c raydraw_bonus.c colours_bonus.c
BMEMORY	= fail_exit_bonus.c clean_exit_bonus.c clean_array_bonus.c
BUTILS	= global_bonus.c time_bonus.c map_bonus.c img_conversion_bonus.c \
		  file_checks_bonus.c map_utils_bonus.c \
		  texture_utils_bonus.c find_player_bonus.c array_utils_bonus.c \
		  parse_utils_bonus.c ft_alt_split_bonus.c
BMAP	= map_checker_bonus.c
OBJS	= $(addprefix $(OBJS_DIR), $(SOURCE_LST:.c=.o))
B_OBJS	= $(addprefix $(OBJS_DIR), $(BONUS_LST:.c=.o))
LIBFT	= -L ./libft
MLX		= -L ./mlx

# ============================ Folder Structures ===============================

HEADERS		= ./includes/
SOURCE_DIR	= $(addprefix ./src/, main.c) \
			  $(addprefix ./src/utils/, $(UTILS)) \
			  $(addprefix ./src/engine/, $(ENGINE)) \
			  $(addprefix ./src/memory/, $(MEMORY)) \
			  $(addprefix ./src/parsing/, $(PARSER)) \
			  $(addprefix ./src/map/, $(MAP)) 
BONUS_DIR	= $(addprefix ./bonus/, main_bonus.c) \
			  $(addprefix ./bonus/utils/, $(BUTILS)) \
			  $(addprefix ./bonus/engine/, $(BENGINE)) \
			  $(addprefix ./bonus/memory/, $(BMEMORY)) \
			  $(addprefix ./bonus/parsing/, $(BPARSER)) \
			  $(addprefix ./bonus/map/, $(BMAP)) 
OBJS_DIR	= ./objs/
SOURCE_LST	= main.c $(ENGINE) $(MEMORY) $(UTILS) $(PARSER) $(MAP)
BONUS_LST	= main_bonus.c $(BENGINE) $(BMEMORY) $(BUTILS) $(BPARSER) $(BMAP)
LIBFT_DIR	= ./libft/
MLX_DIR		= ./mlx/

# ============================ Commands & Flags ===============================

CC			= cc
RM			= rm -rf
#AR			= ar -rcs
FLAGS		= -Wall -Wextra -Werror -O3 #-g -pg
LEAKS		= -g -fsanitize=address
DEBUG		= -DDEBUG
MAKE_FLAG	= --no-print-directory
LDLIBS		= -lft
MLX_FLAGS	= -lmlx -lX11 -lXext -lm

# =========================== Ansi Escape Codes ================================

ULINE	= \e[4m
BLINK	= \e[5m
BLACK 	= \e[1;30m
RED 	= \e[1;31m
GREEN 	= \e[1;32m
YELLOW 	= \e[1;33m
BLUE	= \e[1;34m
PURPLE 	= \e[1;35m
CYAN 	= \e[1;36m
WHITE 	= \e[1;37m
RESET	= \e[0m

# ================================ Rules =======================================
#For debug compilation make debug=1

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)libft$(RESET)"
	make $(MAKE_FLAG) -C $(LIBFT_DIR)
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)minilibx$(RESET)"
	make $(MAKE_FLAG) -sC $(MLX_DIR)
	echo "[$(CYAN)$(BLINK)Linking...$(RESET)]"
ifdef debug
	$(CC) $(FLAGS) $(LEAKS) $(LIBFT) $(MLX) -o $@ $^ $(LDLIBS) $(MLX_FLAGS)
else
	$(CC) $(FLAGS) $(LIBFT) $(MLX) -o $@ $^ $(LDLIBS) $(MLX_FLAGS)
endif
	echo "\n*************************$(GREEN)$(BLINK)    "\
		"[Compilation Sucessfull!]    $(RESET)*************************\n"

$(BONUS): $(B_OBJS)
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)libft$(RESET)"
	make $(MAKE_FLAG) -C $(LIBFT_DIR)
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)minilibx$(RESET)"
	make $(MAKE_FLAG) -sC $(MLX_DIR)
	echo "[$(CYAN)$(BLINK)Linking...$(RESET)]"
ifdef debug
	$(CC) $(FLAGS) $(LEAKS) $(LIBFT) $(MLX) -o $@ $^ $(LDLIBS) $(MLX_FLAGS)
else
	$(CC) $(FLAGS) $(LIBFT) $(MLX) -o $@ $^ $(LDLIBS) $(MLX_FLAGS)
endif
	echo "\n*************************$(GREEN)$(BLINK)    "\
		"[Compilation Sucessfull!]    $(RESET)*************************\n"

$(OBJS):
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
ifdef debug
	$(CC) $(FLAGS) $(LEAKS) -c $(SOURCE_DIR) -I $(HEADERS) $(DEBUG)
else
	$(CC) $(FLAGS) -c $(SOURCE_DIR) -I $(HEADERS)
endif
	mv $(SOURCE_LST:.c=.o) $(OBJS_DIR)

$(B_OBJS):
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
ifdef debug
	$(CC) $(FLAGS) $(LEAKS) -c $(BONUS_DIR) -I $(HEADERS) $(DEBUG)
else
	$(CC) $(FLAGS) -c $(BONUS_DIR) -I $(HEADERS)
endif
	mv $(BONUS_LST:.c=.o) $(OBJS_DIR)

clean:
	make clean $(MAKE_FLAG) -C $(LIBFT_DIR)
	make clean $(MAKE_FLAG) -sC $(MLX_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)cube3D's Objects have been" \
		"removed sucessfully$(RESET)    +++++++++++++++\n\n"

fclean: clean
	make fclean $(MAKE_FLAG) -C $(LIBFT_DIR)
	make clean $(MAKE_FLAG) -sC $(MLX_DIR)
	$(RM) $(NAME)
	$(RM) $(BONUS)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)cube3D's Static library and "\
		"programs removed successfully$(RESET)    +++++++++++++++\n\n"

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(name) \
		maps/valid/test.cub
bleak: bonus 
	valgrind --leak-check=full --show-leak-kinds=all ./$(BONUS) \
		maps/valid/test.cub

run: re
	./$(NAME) maps/valid/test.cub

.SILENT:

.PHONY: all clean fclean re
