#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/06 09:48:57 by jgranet           #+#    #+#              #
#    Updated: 2014/05/06 09:52:16 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

SRC = main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

%.o:%.c
	gcc $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all