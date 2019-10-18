# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 17:42:35 by gwaymar-          #+#    #+#              #
#    Updated: 2019/10/19 01:29:32 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1

# SRCS files
SRCS_PATH := ./srcs
SRCS_FILES := main.c color_pixel.c\
							camera/camera.c\
							cast_ray/cast_ray.c\
							cast_ray/intersecray_sphere.c\
							cast_ray/intersecray_conus.c\
							cast_ray/intersecray_cylinder.c\
							cast_ray/intersecray_plane.c\
							cast_ray/normal_objs.c\
							drawer/draw_scene1.c\
							objects/fill_all_obj.c\
							objects/get_objs.c\
							objects/sphere.c\
							objects/cone.c\
							objects/cylinder.c\
							objects/plane.c\
							objects/x_exec_obj.c\
							objects/x_init_obj.c\
							objects/x_load_num.c\
							read_init/sdl_error.c\
							read_init/read_init.c\
							sdl_render/sdl_loop.c\
							sdl_render/sdl_render.c\
							scene/scene1.c\
							scene/scene2.c\
							scene/scene3.c\
							scene/scene4.c\
							scene/scene5.c\
							surface_sdl/surface.c\
							vectors/new_vec.c\
							vectors/normal_vec.c\
							vectors/op_vec.c\
							vectors/rotate_vec.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

# OBJ files
OBJECTS_PATH := ./objs
OBJECTS_FILES := $(SRCS_FILES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/, $(OBJECTS_FILES))
SUB_DIR_OBJ := $(patsubst %, $(OBJECTS_PATH)/%, $(notdir $(shell find $(SRCS_PATH) -type d -not -path $(SRCS_PATH))))

# cc FLAGS
CC := gcc
#CCFLAGS := -Wall -Wextra -Werror
CCFLAGS := -g

# SDL2
SDL_PATH := ./sdl2/Frameworks
SDL_NAME := SDL2
SDL_INC := -I $(addprefix $(SDL_PATH)/,SDL2.framework/Versions/A/Headers)
SDL_LNK := -framework SDL2 -F $(SDL_PATH)
SDL_rpath := -rpath $(SDL_PATH)
SDL_IMAGE_INC := -I $(addprefix $(SDL_PATH)/,SDL2_image.framework/Versions/A/Headers/)
SDL_TTF_INC := -I $(addprefix $(SDL_PATH)/,SDL2_ttf.framework/Versions/A/Headers)
SDL_MIXER_INC := -I $(addprefix $(SDL_PATH)/,SDL2_mixer.framework/Versions/A/Headers)
SDL_IMAGE_LNK := -framework SDL2_image -F $(SDL_PATH)
SDL_TTF_LNK := -framework SDL2_ttf -F $(SDL_PATH)
SDL_MIXER_LNK := -framework SDL2_mixer -F $(SDL_PATH)
SDL2 := $(SDL_rpath) $(SDL_LNK) $(SDL_IMAGE_LNK) $(SDL_TTF_LNK) $(SDL_MIXER_LNK)

# libft
LIB_PATH := ./lib/libft
LIB_NAME := LibFT
LIB := $(addprefix $(LIB_PATH)/,libft.a)
LIB_INC := -I $(LIB_PATH)
LIB_LNK := -L $(LIB_PATH) -l ft

# include lib and minilibX
INCLUDES := $(LIB_INC) $(SDL_INC) $(SDL_IMAGE_INC) $(SDL_TTF_INC) $(SDL_MIXER_INC) -I ./includes
HEADER := ./includes/rtv1.h ./includes/rtv1_prototypes.h\
					./includes/rtv1_structs.h ./includes/rtv1_vec3.h

# console colors
RESET := \033[0m
RED := \033[31m
BLUE := \033[34m
YELLOW := \033[33m
GREEN := \033[32m
BOLD := \033[1m
MAGEN := \033[35m
CUSTOM := \033[38;5;93m
GRAY := \033[38;5;246m
L_GRAY := \033[38;5;242m
INVERT := \033[7m
SUCCESS := [$(GREEN)✓$(RESET)]
SUCCESS_OK := [$(GREEN)OK$(RESET)]
# clear_row (delete all symymbols)
CLEAR_ROW := @echo "\033[1A\033[K\033[1A"

#	First target
all: $(NAME)

$(OBJECTS): $(OBJECTS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER) | $(SUB_DIR_OBJ) $(OBJECTS_PATH)
	@echo "$(SUCCESS)  $@ "
	@$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(OBJECTS_PATH):
	@mkdir -p $(OBJECTS_PATH) > /dev/null

$(SUB_DIR_OBJ):
	@mkdir -p $(OBJECTS_PATH) $(SUB_DIR_OBJ) > /dev/null

$(LIB): | $(HEADER)
	@echo "$(BOLD)$(RED) > $(CUSTOM)Compilation $(NAME)$(RESET)"

$(NAME): $(LIB) $(OBJECTS) $(HEADER)
	@echo "$(GRAY) Creating OBJ .o   $(RESET)$(SUCCESS_OK)"
	@echo "$(GRAY) $(LIB_NAME)             $(RESET)[$(YELLOW)Compiling...$(RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(GRAY) $(LIB_NAME)             $(RESET)$(SUCCESS_OK)"
	@echo "$(GRAY) Compiling... $(NAME)$(RESET)"
	@$(CC) $(SDL2) $(CCFLAGS) $(OBJECTS) $(LIB_LNK) -o $(NAME)
	$(CLEAR_ROW)
	@echo "$(GRAY) Compiling... $(BOLD)$(NAME)$(CUSTOM) > Successful ✓$(RESET)"

#	Removing objects
clean:
	@echo "$(L_GRAY)removing  object files - ...$(RESET)"
	@make -C $(LIB_PATH) clean > /dev/null
	@rm -rf $(OBJECTS_PATH) > /dev/null
	$(CLEAR_ROW)
	@echo "$(L_GRAY)removing  object files - done$(RESET)"

#	Removing objects and project_launcher
fclean: clean
	@echo "$(L_GRAY)removing  $(NAME) - ...$(RESET)"
	@make -C $(LIB_PATH) fclean > /dev/null
	@rm -rf $(NAME) > /dev/null
	$(CLEAR_ROW)
	@echo "$(L_GRAY)removing  $(NAME) - done$(RESET)"

#	All removing then compiling
re: fclean all
