#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/06 09:48:57 by jgranet           #+#    #+#              #
#    Updated: 2014/05/07 17:13:48 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

SRC = main.c ft_exit.c list.c ft_distrib_status.c ft_print.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c

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