#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/06 09:48:57 by jgranet           #+#    #+#              #
#    Updated: 2014/05/10 19:00:48 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

SRC = main.c ft_exit.c list.c ft_distrib_status.c ft_print.c ft_status.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c \
	term.c ft_tputs_putchar.c ft_strncmp.c ft_put.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I includes

TERMCAP = -L /usr/lib -ltermcap

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(TERMCAP)

%.o:%.c
	gcc $(FLAGS) -c $(SRC) $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all