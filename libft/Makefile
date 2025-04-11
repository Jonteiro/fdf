# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 14:06:44 by josilvei          #+#    #+#              #
#    Updated: 2025/04/03 15:04:08 by jsilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

OBJ_LIB = Obj_Dir


SRC = $(addprefix src_lib/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
		
PRINTF_SRCS = $(addprefix ft_printf/, ft_printf_utils.c ft_printf_utils2.c ft_printf.c)

GNL_SRCS = $(addprefix ft_gnl/, get_next_line_utils.c  get_next_line.c)

OBJ = $(addprefix $(OBJ_LIB)/, $(notdir $(SRC:.c=.o)))

PRINTF_OBJ = $(addprefix $(OBJ_LIB)/, $(notdir ${PRINTF_SRCS:.c=.o}))

GNL_OBJ = $(addprefix $(OBJ_LIB)/, $(notdir ${GNL_SRCS:.c=.o}))

all: $(OBJ_LIB) ${NAME}

${NAME}: ${OBJ} ${PRINTF_OBJ} ${GNL_OBJ}
	ar rcs $@ $^

$(OBJ_LIB)/%.o: src_lib/%.c | $(OBJ_LIB)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_LIB)/%.o: ./ft_printf/%.c | $(OBJ_LIB)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LIB)/%.o: ./ft_gnl/%.c | $(OBJ_LIB)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LIB):
	mkdir -p $(OBJ_LIB)

clean:
	${RM} ${OBJ_LIB}

fclean: clean
	${RM} ${OBJ_LIB}

re:	fclean all
