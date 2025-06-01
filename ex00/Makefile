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

NAME=bin/megaphone
MAIN=megaphone.cpp
COMPILER=c++
COMPILER_ARGS=-Wall -Wextra -Werror -std=c++98
MAIN_OBJECT=$(addprefix obj/, $(patsubst %.cpp, %.o, $(MAIN)))

all: $(NAME)

$(NAME): $(MAIN_OBJECT)
	$(COMPILER) $(COMPILER_ARGS) $(MAIN_OBJECT) -o $@

obj/%.o: %.cpp
	@mkdir -p $(dir $(NAME))
	@mkdir -p $(dir $(MAIN_OBJECT))
	$(COMPILER) $(COMPILER_ARGS) -c $< -o $@

clean:
	rm -rf $(dir $(MAIN_OBJECT))

fclean: clean
	rm -rf $(NAME)

re: fclean all
