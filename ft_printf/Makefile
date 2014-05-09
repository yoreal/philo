#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 10:31:15 by jgranet           #+#    #+#              #
#    Updated: 2014/05/09 18:21:29 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
HEADER = -I includes
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_strcat.c \
	ft_strdup.c ft_itoa.c ft_strjoin.c ft_strcpy.c ft_strnew.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	gcc $(FLAGS) -c $(SRC) $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
