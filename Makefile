# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 13:37:11 by plashkar          #+#    #+#              #
#    Updated: 2023/10/10 20:55:11 by plashkar         ###   ########.fr        #
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
	src/move.c \
	src/game.c \
	src/image.c \



# BONUS = \
# 	bonus_files/checker_utils.c \
# 	bonus_files/push_and_swap_checker.c \
# 	bonus_files/reverse_rotate_checker.c \
# 	bonus_files/rotate_checker.c \

OBJ = $(SRC:.c=.o)

# BOBJS = $(BONUS:.c=.o)

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(NAME)

# bonus: $(SO_LONG_LIB) $(OBJ) $(BOBJS)
# 	@echo "Compiling $@"
# 	@$(CC) $(STANDARD_FLAGS) $(MINILIBX_FLAGS) $(INCLUDE) bonus_files/bonus_main.c  $(OBJ) $(BOBJS) $(LIBFT_A) $(SO_LONG_LIB) -o BONUSNAME > /dev/null
# 	@echo "bonus has been created."

$(NAME): $(SO_LONG_LIB) $(OBJ)
	@echo "Compiling $@"
	@make -C minilibx-linux
	@$(CC) $(STANDARD_FLAGS) $(INCLUDE) src/main.c  $(OBJ) $(LIBFT_A) $(SO_LONG_LIB) $(MINILIBX_FLAGS) -o $(NAME) > /dev/null
	@echo "so_long has been created."

$(SO_LONG_LIB): $(OBJ)
	@echo "Creating $@"
	@make -C $(LIBFT_DIR) > /dev/null
	@ar rcs $(SO_LONG_LIB) $(OBJ) $(LIBFT_A) > /dev/null
	@echo The library push_swap.a has been created.

clean:
	@rm -f src/*.o
	@rm -f checker_files/*.o
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo Object files have been deleted.


fclean: clean
	@rm -f $(SO_LONG_LIB)
	@rm -f $(NAME)
	@rm -f checker
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo All created files have been deleted.

re: fclean all

.PHONY: fclean clean all re
