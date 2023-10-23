# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 13:37:11 by plashkar          #+#    #+#              #
#    Updated: 2023/10/19 21:30:26 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g #-fsanitize=address
MINILIBX_FLAGS	= minilibx-linux/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDE = -Iincludes

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SO_LONG_LIB = so_long.a

SRC = \
	src/utils.c \
	src/map_checks.c \
	src/path_checks.c \
	src/map.c \
	src/player_move.c \
	src/player_attack.c \
	src/player_animations.c \
	src/enemy_animations.c \
	src/enemy.c \
	src/game.c \
	src/image.c \
	src/game_over.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SO_LONG_LIB) $(OBJ)
	@echo "Compiling $@"
	@make -C minilibx-linux
	@$(CC) $(STANDARD_FLAGS) $(INCLUDE) src/main.c  $(OBJ) $(LIBFT_A) $(SO_LONG_LIB) $(MINILIBX_FLAGS) -o $(NAME) > /dev/null
	@echo "so_long has been created."

$(SO_LONG_LIB): $(OBJ)
	@echo "Creating $@"
	@make -C $(LIBFT_DIR) > /dev/null
	@ar rcs $(SO_LONG_LIB) $(OBJ) $(LIBFT_A) > /dev/null
	@echo The library so_long.a has been created.

clean:
	@rm -f src/*.o
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo Object files have been deleted.


fclean: clean
	@rm -f $(SO_LONG_LIB)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo All created files have been deleted.

re: fclean all

.PHONY: fclean clean all re
