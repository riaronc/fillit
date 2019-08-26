# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbasnaka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 14:45:10 by sbasnaka          #+#    #+#              #
#    Updated: 2018/12/29 14:45:34 by sbasnaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = backtrack.c faults.c hashes.c lists.c matrix.c validation.c main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = header.h

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME)
	@echo "Fillit is OK"

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:	
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
