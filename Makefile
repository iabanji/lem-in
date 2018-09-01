# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giabanji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 19:02:03 by giabanji          #+#    #+#              #
#    Updated: 2018/02/28 19:02:54 by giabanji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c get_next_line.c trafic.c valid.c addit.c search.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd libft/ && $(MAKE)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: clean all
