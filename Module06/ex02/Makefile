
NAME		= identify
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror  -std=c++98
RM			= rm -rf

OBJDIR = objs

HEADERS		= A.hpp B.hpp C.hpp Base.hpp
SRC			= main.cpp Base.cpp
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