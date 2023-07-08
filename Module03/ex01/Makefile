# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:28:48 by otait-ta          #+#    #+#              #
#    Updated: 2023/07/08 10:27:41 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= ScavTrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror  -std=c++98
RM			= rm -rf

OBJDIR = objs

HEADERS		= ClapTrap.hpp  ScavTrap.hpp
SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp
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