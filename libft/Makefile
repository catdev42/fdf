# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/04/10 15:20:16 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

GNLNAME = get_next_line.a
GNLDIR = ./get_next_line
GNL = ./get_next_line/get_next_line.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_freetab.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c  ft_lstnew.c ft_lstsize.c ft_lstmap.c \
./printf/ft_print_hex.c ./printf/ft_print_int.c ./printf/ft_print_uns.c ./printf/ft_printf_words.c ./printf/ft_printf.c \
./get_next_line/get_next_line.c

OBJS     	= $(SRC:.c=.o)

BONUS		= 
BONUS_OBJS	= $(BONUS:.c=.o)

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

$(NAME): $(OBJS)
	ar rc  $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -rf $(NAME)
	
re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)


#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
