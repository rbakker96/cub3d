# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 08:44:29 by rbakker           #+#    #+#              #
#    Updated: 2020/02/06 13:14:58 by rbakker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		liblist.a

SOURCES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
OBJECTS_S =	${SOURCES:%.c=%.o}

FLAGS =		-Wall -Wextra -Werror
COMPILE	=	gcc
LIB	=		ar rc

GREEN = \033[38;5;46m
WHITE = \033[38;5;15m
GREY = \033[38;5;8m
ORANGE= \033[38;5;202m
RED = \033[38;5;160m

all: $(NAME)

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS_S)
	@echo "$(ORANGE)Creating library..."
	@$(LIB) $(NAME) $(OBJECTS_S) $?
	@echo "$(GREEN)Succesful"

clean:
	@echo "$(RED)DELETING OBJECTFILES"
	@/bin/rm -f $(OBJECTS_S)
	@/bin/rm -f $(OBJECTS_B)

fclean: clean
	@echo "$(RED)DELETING EXECUTABLE"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
