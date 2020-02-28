# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 14:55:09 by rbakker           #+#    #+#              #
#    Updated: 2020/02/28 16:47:54 by rbakker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SOURCES	= 	main.c \
			parse/parse.c \
			parse/parse_file_one.c \
			parse/parse_file_two.c \
			utils/parse_utils_one.c \
			utils/parse_utils_two.c \
			utils/parse_utils_three.c \
			utils/validate_map.c \
			utils/free_reset_utils.c

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
	@echo "$(GREEN)Succesfuly creating exe 'minirt'"

%.o: %.c
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

re: fclean all

.PHONY: all clean fclean re
