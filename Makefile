# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 12:22:13 by jsilveir          #+#    #+#              #
#    Updated: 2025/04/11 15:13:47 by jsilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=fdf
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
OBJ_DIR= Obj_Fdf
SRC_DIR= Src
LIBFT= libft/libft.a
MLX= mlx/libmlx.a

SRC_FILES= fdf.c

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lm -lz -lXext -lX11 -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@

$(LIBFT):
	@make -C ./libft -s
	
$(MLX):
	@make -C ./mlx -s

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./Libft -s
	@make clean -C ./mlx -s
	
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	
re: fclean all

r:
	make && clear && ./fdf Maps/42.fdf

.PHONY: all fclean clean re