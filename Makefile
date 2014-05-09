#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/06 09:48:57 by jgranet           #+#    #+#              #
#    Updated: 2014/05/09 10:19:55 by jgranet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

SRC = main.c ft_exit.c list.c ft_distrib_status.c ft_print.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

HEADER = -I includes

LPRINTF = -L./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LPRINTF)

%.o:%.c
	gcc $(FLAGS) -c $(SRC) $(HEADER)

clean:
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
	make re -C ft_printf