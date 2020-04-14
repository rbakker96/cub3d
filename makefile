# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbakker <rbakker@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/05 14:55:09 by rbakker       #+#    #+#                  #
#    Updated: 2020/04/14 11:20:18 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SOURCES	= 	main.c \
			error/error_functions.c \
			error/free_functions.c \
			error/reset_functions.c \
			mlx_functions/init_mlx.c \
			mlx_functions/create_texture.c \
			mlx_functions/create_image.c \
			mlx_functions/create_sprite.c \
			mlx_functions/close_screen.c \
			bmp/create_bmp.c \
			bmp/get_rgb_color.c \
			parse/parse_general_input.c \
			parse/parse_map_input.c \
			parse/parse_texture_input.c \
			parse/parse.c \
			parse/validate_general_input.c \
			parse/validate_read_lines.c \
			parse/flood_fill_map_check.c \
			parse/validate_resolution.c \
			render/render.c \
			render/camera_calc.c \
			render/direction_calc.c \
			render/distance_calc.c \
			render/plane_calc.c \
			render/position_calc.c \
			render/draw.c \
			render/wall_calc.c \
			render/reset_variables.c \
			render/set_color.c \
			movement/move_calc.c \
			movement/turn_calc.c \
			movement/register_movement.c \
			texture/texture_color.c \
			texture/texture_calc.c \
			texture/tex_x.c \
			texture/wall_x.c \
			sprites/sort_sprites.c \
			sprites/sprite_dimensions.c \
			sprites/sprite_position.c \
			sprites/sprites.c \
			sprites/transform_position.c \
			sprites/sprite_color.c

OBJECTS =	${SOURCES:%.c=%.o}

FLAGS 	=	-Wall -Wextra -Werror
COMPILE	=	gcc
LIB		=	ar rc

GREEN 	= 	\033[38;5;46m
WHITE 	= 	\033[38;5;15m
GREY 	= 	\033[38;5;8m
ORANGE 	= 	\033[38;5;202m
RED 	= 	\033[38;5;160m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(WHITE)Working on gnl...			$(WHITE)"
	@make -C gnl
	@echo "$(WHITE)Working on libft...			$(WHITE)"
	@make -C libft
	@echo "$(WHITE)Working on list...			$(WHITE)"
	@make -C list
	@echo "$(WHITE)Working on mlx...			$(WHITE)"
	@make -C mlx
	@echo "$(ORANGE)Creating on miniRT...			$(WHITE)"
	@$(COMPILE) -Lmlx -lmlx -Lgnl -lgnl -Llist -llist -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS)
	@echo "$(GREEN)Succesfuly creating exe 'cube3d'"
	@mv mlx/libmlx.dylib .

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -Imlx -Ilibft -Ignl -Ilist -c -o $@ $<

clean:
	@echo "$(WHITE)Working on gnl..."
	@make clean -C gnl
	@echo "$(WHITE)Working on libft..."
	@make clean -C libft
	@echo "$(WHITE)Working on list..."
	@make clean -C list
	@echo "$(WHITE)Working on mlx..."
	@make clean -C mlx
	@echo "$(WHITE)Working on miniRT..."
	@echo "$(RED)DELETING OBJECTFILES"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(WHITE)Working on gnl..."
	@make fclean -C gnl
	@echo "$(WHITE)Working on libft...	"
	@make fclean -C libft
	@echo "$(WHITE)Working on list...	"
	@make fclean -C list
	@echo "$(WHITE)Working on miniRT...	"
	@echo "$(RED)DELETING EXECUTABLE"
	@/bin/rm -f $(NAME)
	@/bin/rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
