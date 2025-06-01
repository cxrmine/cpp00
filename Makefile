# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalkawi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 13:39:17 by tmalkawi          #+#    #+#              #
#    Updated: 2025/06/01 13:39:17 by tmalkawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megaphone
MAIN=megaphone.cpp
COMPILER=c++
COMPILER_ARGS=-Wall -Wextra -Werror -std=c++98
MAIN_OBJECT=test

$(NAME):
	$(COMPILER) $(COMPILER_ARGS) $(MAIN) -o $@

%.cpp: %.o
	$(COMPILER) $(COMPILER_ARGS) $@ -o $<

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
