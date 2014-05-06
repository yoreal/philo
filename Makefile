#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/06 09:48:57 by jgranet           #+#    #+#              #
#    Updated: 2014/05/06 16:57:27 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

SRC = main.c ft_exit.c list.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(HEADER)

%.o:%.c
	gcc $(FLAGS) -c $(SRC) $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all