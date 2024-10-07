CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -I.


##################
##	LIBRARIES	##
##################

MLX_PATH	= minilibx-linux/
MLX			= $(MLX_PATH)libmlx.a
MLX_INC		= $(MLX_PATH)

##################
##	 INCLUDE	##
##################

INC_LST =	.	\
			./$(MLX_INC)
INCLUDE = $(addprefix -I, $(INC_LST))

##################
##	  SOURCE	##
##################

SRC_DIR		= srcs/
SRC_LIST = 	burningship.c \
			create_fractal.c \
			ft_putstr_fd.c \
			ft_strncmp.c \
			ft_tolower.c \
			handle_events.c \
			init_fractal.c \
			julia.c \
			mandelbrot.c \
			math.c \
			main.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))


######################
##	 OBJECTS/NAME	##
######################

NAME 		= fractol

OBJ_DIR 	= obj/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))


#################
##	 COLORS	   ##
#################

COLOR_RESET		=	\033[0m
COLOR_GREEN		=	\033[38;5;76m
COLOR_RED		=	\033[38;5;160m
COLOR_BLUE		=	\033[38;5;45m
COLOR_ORANGE	=	\033[38;5;220m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m

################
##	PROGRESS  ##
################

COMPILED_SRCS		:=	1

TOTAL_SRCS			:=	$(words $(SRC))


MAX_PATH_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' | awk '{print length}' | sort -nr | head -n1)
MAX_NAME_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' -exec basename {} \; | awk '{ print length }' | sort -nr | head -n1)

define progress_bar
	printf "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"; \
	for i in $$(seq 1 $(4)); do \
		if [ $$i -le $$(($(1)*$(4)/$(2))) ]; then \
			printf "#"; \
		else \
			printf "."; \
		fi; \
	done; \
	printf "$(COLOR_BLUE)] $(BOLD)$(1)/$(2) $(COLOR_GREEN)$(3)$(COLOR_RESET)\r"
endef

define print_progress
	@$(eval WIDTH := $(shell tput cols))
	@$(eval LEN := $(shell expr $(WIDTH) - $(MAX_PATH_LENGTH) - 26))
	
	@printf "\033[2K"; \
	if [ $(LEN) -le 10 ]; then \
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\r"; \
	else \
		$(call progress_bar,$(1),$(2),$(3),$(LEN)); \
	fi
endef

###############
##	 RULES	 ##
###############

all: $(MLX) $(NAME)

$(MLX):
	@make -sC $(MLX_PATH) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS))

##################
## 	 GENERAL	##
##################

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(INCLUDE) -lXext -lX11 -lm
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Fract-ol is Ready !$(COLOR_RESET)"

clean:
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME) objects$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME)$(COLOR_RESET)"
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete $(MLX)$(COLOR_RESET)"
	@rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re