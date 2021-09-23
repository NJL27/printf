# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:10:41 by nlenoch           #+#    #+#              #
#    Updated: 2021/08/19 18:03:18 by nlenoch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -f

SOURCES = ft_printf.c ft_putchar.c ft_putnbr.c \
			ft_putunbr.c ft_puthex.c ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -c $(SOURCES)
	ar -crs $(NAME) $(OBJECTS)

clean:
	$(RM) $(RM_FLAGS) $(OBJECTS)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all
