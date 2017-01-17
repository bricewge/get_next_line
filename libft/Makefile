#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <brice.wge@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2016/12/21 14:18:28 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc -fPIC
CFLAGS = -Wall -Wextra -Werror
COPT = -I ./
CDEBUG = -g
NAME = libft.a

SOURCES = $(shell ls | grep ^ft_ | grep '\.c$$')
OBJECTS = $(shell ls | grep ^ft_ | grep '\.c$$' | sed 's/\.c$$/.o/')

HEADERS = libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(COPT) -c $(SOURCES)

debug: $(NAME)-debug

$(NAME)-debug : $(SOURCES) $(HEADERS)
		$(CC) $(CFLAGS) $(COPT) -o $(NAME)-debug $(CDEBUG) -c $(SOURCES)

library:
	$(CC) -shared $(OBJECTS) -o libft.so

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME) $(NAME)-debug

re: fclean all
