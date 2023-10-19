# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 11:32:48 by otait-ta          #+#    #+#              #
#    Updated: 2023/10/19 15:37:23 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= result
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror  -std=c++98
RM			= rm -rf

OBJDIR = objs

HEADERS		= easyfind.hpp easyfind.tpp
SRC			= main.cpp
OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS)  -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re 