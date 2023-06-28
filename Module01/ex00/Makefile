
NAME		= zombieHorde
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = objs

HEADERS		= Zombie.hpp
SRC			= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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