# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/04/23 18:45:00 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

MLX		= ./minilibx-linux/libmlx_Linux.a
MLXDIR	= ./minilibx-linux

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= ./include
OBJDIR		:= ./obj
SRC     	:= calcpoints.c events.c init.c main.c math_utils.c parse.c render.c
OBJS     	:= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g -fPIC

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
.SILENT:

all: $(NAME)

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(HEADERS)

runlibft:
	$(MAKE) -C $(LIBDIR)

runlibmlx:
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	$(MAKE) -C $(MLXDIR)

$(NAME): runlibft runlibmlx $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean
	rm -rf $(MLXDIR)


re: fclean all

.PHONY: all clean fclean re
