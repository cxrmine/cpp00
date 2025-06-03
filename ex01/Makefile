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

BUILD_PATH=bin
OBJ_PATH=obj
NAME=$(BUILD_PATH)/livrejaunepointfr
SRC=main.cpp \
	PhoneBook.cpp \
	Contact.cpp \

INCLUDES=-I.
COMPILER=c++
COMPILER_ARGS=-Wall -Wextra -Werror -std=c++98 -g3 $(INCLUDES)
MAIN_OBJECT=$(addprefix $(OBJ_PATH)/, $(patsubst %.cpp, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(MAIN_OBJECT)
	$(COMPILER) $(COMPILER_ARGS) $(MAIN_OBJECT) -o $@

$(OBJ_PATH)/%.o: %.cpp
	@mkdir -p $(dir $(NAME))
	@mkdir -p $(dir $(MAIN_OBJECT))
	$(COMPILER) $(COMPILER_ARGS) -c $< -o $@

clean:
	rm -rf ./obj

fclean: clean
	rm -rf $(NAME)

re: fclean all
