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

NAME	= AMateria
SOURCE	= main.cpp #AMateria.cpp ICharacter.cpp Character.cpp\
		  ImateriaSource.cpp Ice.cpp Cure.cpp
OBJS	= $(addprefix $(OBJS_DIR), $(SOURCE:.cpp=.o))

# ============================ Folder Structures ===============================

HEADERS		= ./includes/
SOURCE_DIR	= $(addprefix ./src/, $(SOURCE))
OBJS_DIR	= ./objs/

# ============================ Commands & Flags ===============================

CC			= c++
RM			= rm -rf
#AR			= ar -rcs
FLAGS		= -Wall -Wextra -Werror -std=c++98
LEAKS		= -g -fsanitize=address
DEBUG		= -DDEBUG
MAKE_FLAG	= --no-print-directory

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

all: $(NAME)

$(NAME): $(OBJS)
	echo "[$(CYAN)$(BLINK)Linking...$(RESET)]"
ifdef debug
	$(CC) $(FLAGS) -o $@ $^ $(LEAK)
else
	$(CC) $(FLAGS) -o $@ $^
endif
	echo "\n*************************$(GREEN)$(BLINK)    "\
		"[Compilation Sucessfull!]    $(RESET)*************************\n"

$(OBJS):
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
ifdef debug
	$(CC) $(FLAGS) -c $(SOURCE_DIR) -I $(HEADERS) $(DEBUG)
else
	$(CC) $(FLAGS) -c $(SOURCE_DIR) -I $(HEADERS)
endif
	mv *.o $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)AMateria's Objects have been" \
		"removed sucessfully$(RESET)    +++++++++++++++\n\n"

fclean: clean
	$(RM) $(NAME)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)AMateria's Static library and "\
		"programs removed successfully$(RESET)    +++++++++++++++\n\n"

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

run: re
	./$(NAME)

.SILENT:

.PHONY: all clean fclean re
