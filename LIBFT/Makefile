# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 05:03:47 by zajaddou          #+#    #+#              #
#    Updated: 2025/01/30 23:16:34 by zajaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = ft_strlen.c \
	ft_strlcpy.c \
	ft_strncpy.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strncmp.c \
	ft_putnbr_fd.c \
	get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar r $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean
