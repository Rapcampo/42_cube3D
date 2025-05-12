# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 13:52:55 by rapcampo          #+#    #+#              #
#    Updated: 2025/05/02 22:56:50 by rapcampo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Files ======================================

NAME	= cub3d
SOURCE	= $(SOURCE_DIR)
#PARSER	= asda
ENGINE	= key_events.c screen_output.c
MEMORY	= fail_exit.c clean_exit.c
UTILS	= global.c
OBJS	= $(addprefix $(OBJS_DIR), $(SOURCE_LST:.c=.o))
LIBFT	= -L ./libft
MLX		= -L ./mlx

# ============================ Folder Structures ===============================

HEADERS		= ./includes/
SOURCE_DIR	= $(addprefix ./src/, main.c) \
			  $(addprefix ./src/utils/, $(UTILS)) \
			  $(addprefix ./src/engine/, $(ENGINE)) \
			  $(addprefix ./src/memory/, $(MEMORY)) 
OBJS_DIR	= ./objs/
SOURCE_LST	= main.c $(ENGINE) $(MEMORY) $(UTILS)
LIBFT_DIR	= ./libft/
MLX_DIR		= ./mlx/

# ============================ Commands & Flags ===============================

CC			= cc
RM			= rm -rf
#AR			= ar -rcs
FLAGS		= -Wall -Wextra -Werror
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

$(OBJS):
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
ifdef debug
	$(CC) $(FLAGS) $(LEAKS) -c $(SOURCE_DIR) -I $(HEADERS) $(DEBUG)
else
	$(CC) $(FLAGS) -c $(SOURCE_DIR) -I $(HEADERS)
endif
	mv $(SOURCE_LST:.c=.o) $(OBJS_DIR)

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
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)cube3D's Static library and "\
		"programs removed successfully$(RESET)    +++++++++++++++\n\n"

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

run: re
	./$(NAME)

.SILENT:

.PHONY: all clean fclean re
