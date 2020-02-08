# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcamilo- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 19:27:53 by rcamilo-          #+#    #+#              #
#    Updated: 2020/02/08 15:47:36 by rcamilo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJS = *.o
CPARAMS = -c
CFLAGS = -Wall -Werror -Wextra
CC = gcc
AR = ar
ARPARAMS = -rc

all: $(NAME)

$(NAME):
	$(CC) $(CPARAMS) $(CFLAGS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

noflags:
	$(CC) $(CPARAMS) $(SRCS)
	$(AR) $(ARPARAMS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

