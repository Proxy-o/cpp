# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 18:10:03 by otait-ta          #+#    #+#              #
#    Updated: 2023/07/06 18:10:04 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= a.out
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror  -std=c++98
RM			= rm -rf

OBJDIR = objs

HEADERS		= Fixed.hpp Point.hpp 
SRC			= main.cpp Fixed.cpp Point.cpp bsp.cpp
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