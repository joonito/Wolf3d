# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 23:41:57 by julee             #+#    #+#              #
#    Updated: 2020/01/31 13:23:20 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

CFLAGS := -Wall -Wextra -Werror

MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

MLXPATH := -L minilibx_macos

INC := $(shell find include -name "*.h")

INCFLAG := -I include

NAME := wolf3d

LIB := ./libft/libft.a

MLX := ./minilibx_macos/libmlx.a

SRC := $(shell find src -name "*.c")

LIBSRC := $(shell find libft/src -name "*.c")

OBJ = $(SRC:.c=.o)

LIBOBJ := $(LIBSRC:.c=.o)

$(NAME): $(OBJ) $(INC) $(LIB) $(MLX)
	@$(CC) $(CFLAGS) $(INCFLAG) -o $(NAME) $(OBJ) $(LIB) $(MLX) $(MLXFLAGS) $(MLXPATH)

$(OBJ): %.o : %.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB): $(LIBOBJ)
	@cd libft && make

$(MLX):
	@cd minilibx_macos && make

.PHONY: clean fclean all re

clean:
	@rm -f $(OBJ)
	@cd libft && make clean
	@cd minilibx_macos && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean	

all: $(NAME)

re: fclean all
