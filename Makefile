# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/04/01 00:20:22 by myakoven         ###   ########.fr        #
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
SRC     	:= main.c
OBJS     	:= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g

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
	$(MAKE) -C $(MLXDIR)

$(NAME): runlibft runlibmlx $(OBJS) 
	gcc poll.c $(LIBFT) -Lminilibx-linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#	gcc *.c $(LIBFT) -Lminilibx-linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean



re: fclean all
