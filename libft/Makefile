# ================================= Files ======================================

NAME	= libft.a
#SOURCE	= $(foreach dir, $(SOURCE_DIR), $(wildcard $(dir)/*.c)) 
SOURCE	= $(SOURCE_DIR)
OBJS	= $(addprefix $(OBJS_DIR), $(SOURCE_LST:.c=.o))
DEPFLG	= -MP -MD
CTYPE	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
LIST	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
STDIO	= ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STDLIB	= ft_atoi.c ft_calloc.c ft_itoa.c
STRING	= ft_bzero.c ft_freematrix.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_memmove.c ft_memset.c ft_split.c ft_split_mult.c ft_stpcpy.c \
		  ft_strchr.c ft_strcmp.c ft_strcspn.c ft_strdup.c ft_striteri.c\
		  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		  ft_strncmp.c ft_strndup.c ft_strnstr.c ft_strpbrk.c ft_strrchr.c \
		  ft_strspn.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		  ft_wordcount_mult.c
GNL		= get_next_line.c get_next_line_utils.c
PRINTF	= ft_printf.c ft_print_nbr.c

# ============================ Folder Structures ===============================

HEADERS		= ../includes/
SOURCE_DIR	= $(addprefix ./srcs/ctype/, $(CTYPE))\
			  $(addprefix ./srcs/list/, $(LIST))\
			  $(addprefix ./srcs/stdio/, $(STDIO))\
			  $(addprefix ./srcs/stdlib/, $(STDLIB))\
			  $(addprefix ./srcs/string/, $(STRING))\
			  $(addprefix ./srcs/printf/, $(PRINTF))\
			  $(addprefix ./srcs/gnl/, $(GNL))
#SOURCE_DIR	= ./srcs/ctype/ ./srcs/list/ ./srcs/stdio/ ./srcs/stdlib/\
			  ./srcs/string/ ./srcs/printf/ ./srcs/gnl/
OBJS_DIR	= objs/
SOURCE_LST	= $(CTYPE) $(LIST) $(STDIO) $(STDLIB) $(STRING) $(GNL) $(PRINTF)

# ============================ Commands & Flags ===============================

CC			= cc
RM			= rm -rf
AR			= ar -rcs
FLAGS		= -Wall -Werror -Wextra -I$(HEADERS) #$(DEPFLG)
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

#vpath %.c $(SOURCE_DIR)

all: $(NAME)

$(NAME): $(OBJS)
#	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)libft$(RESET)"
#	echo "[$(CYAN)$(BLINK)Linking...$(RESET)]"
	$(AR) $(NAME) $(OBJS)
	echo "\n*************************$(GREEN)$(BLINK)"\
		"[Libft Sucessfull!]    $(RESET)*************************\n"

$(OBJS): 
#	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
	$(CC) $(FLAGS) -c $(SOURCE)
	mv $(SOURCE_LST:.c=.o) $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
